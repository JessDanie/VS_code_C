#include <reg51.h>
#include <stdio.h>
#include <intrins.h>
#include <absacc.h>
#define uchar unsigned char
#define uint unsigned int
#define my_data_ADC0 XBYTE[0XA000]
void key();
void DelayMS(uint x);
void myint0();
void showkey(uchar b, uchar pos);
void readADC();

uchar xdata KEYIN _at_ 0x8001;
uchar xdata DIGIT _at_ 0x8002;
uchar xdata SEG _at_ 0x8004;
uchar xdata DACS _at_ 0x9000;
uchar xdata ADCS _at_ 0xa000;
uchar scankey();
uchar TestKey();
uchar adresult, status, time, speed;
uchar chartochow[6];
uchar code SEGCC[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, 0x77, 0x7C, 0x39, 0x4f, 0x79, 0x71, 0x08}; // 0x08 -->'_'
//uchar code SEGLOCAL[] = {0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};
uchar code KeyTable[ ] = {   // 键码定义
  0x16, 0x15, 0x14, 0xff,
  0x13, 0x12, 0x11, 0x10,
  0x0d, 0x0c, 0x0b, 0x0a,
  0x0e, 0x03, 0x06, 0x09,
  0x0f, 0x02, 0x05, 0x08,
  0x00, 0x01, 0x04, 0x07
};
uint level = 0,timer_count = 0,left_time = 0,off_time = 0,start_time_mode = 0;
uint code DA_LEVEL[] = {160, 172, 184, 196, 208, 220, 232, 244, 255};
bit p_status = 0;
bit on_off = 0;		   // Control the motor on and off;
bit auto_mode = 0;	   // self-control mode
bit set_time_mode = 0; // time_set_control mode
char data now_temperature;
void myinit()
{
	EX1 = ET1 = EA = 1;
	speed = 10;
	time = 10;
	now_temperature = 0;
	off_time = 0;
}
/* time set function*/
void init_time()
{
	left_time = 6; // stop after 6s
	off_time = 0;
	TMOD = 0x01;
	TH0 = (65536 - 50000) / 256;
	TL0 = (65536 - 50000) % 256;
	EA = ET0 = TR0 = 1;
	start_time_mode = 0;
}
void time_0() interrupt 1 // timer 1
{
	TH0 = (65536 - 50000) / 256;
	TL0 = (65536 - 50000) % 256;
	//key();
	timer_count++;
	if (timer_count == 20)//20*50000=1s
	{
		timer_count = 0;
		left_time--;
	}
}
void Delay(uint CNT)
{
	uint i;
	while (CNT-- != 0)
		for (i = 100; i != 0; i--)
			;
}
void key()
{
	if (TestKey()){
		uchar tmp = scankey();
		switch(tmp){
			case 0xa : if (level < 8) level++;break;
			case 0xb : if (level > 0) level--;break;
			case 0xc : p_status = 1;auto_mode = 0;on_off = 1;level = 1*p_status;break;
			case 0xd : p_status = 0;auto_mode = 1;on_off = 1;break;
			case 0xe : set_time_mode = ~set_time_mode;break;
			case 0xf : on_off = ~on_off;break;
			default  : if(tmp < 10 && tmp> 0) off_time += tmp;
		}
	}
}
/* temperature level function*/
void tem_level()
{
	if (now_temperature <= 27)level = 1;
	else if (now_temperature <= 29)level = 2;
	else if (now_temperature <= 31)level = 3;
	else if (now_temperature <= 33)level = 4;
	else if (now_temperature <= 37)level = 5;
	else if (now_temperature <= 39)level = 6;
	else if (now_temperature <= 41)level = 7;
	else if (now_temperature > 41)level = 8;
}
/* temperature level function*/
void main(void)
{
	uint i = 0; // count v
	myinit();
	while (1)
	{
		if (on_off == 1)
		{
			DACS = DA_LEVEL[8];
			if (auto_mode == 0 && set_time_mode == 0)
			{
				DACS = DA_LEVEL[level];
				DelayMS(10);
				readADC();
				chartochow[0]=level / 10,chartochow[1]=level % 10,chartochow[2]=chartochow[3]=16,chartochow[4]=now_temperature / 10,chartochow[5]=now_temperature % 10;
				for(i=0;i<6;i++) showkey(chartochow[i], i+1);
				SEG=0;
				key();
			}
			else if (auto_mode == 1 && set_time_mode == 0)
			{
				tem_level();
				DACS = DA_LEVEL[level];
				DelayMS(10);
				readADC();
				chartochow[0]=level / 10,chartochow[1]=level % 10,chartochow[2]=chartochow[3]=16,
				chartochow[4]=now_temperature / 10,chartochow[5]=now_temperature % 10;
				for(i=0;i<6;i++) showkey(chartochow[i], i+1);
				SEG=0;
				key();
			}
			else if (auto_mode == 1 && set_time_mode == 1)
			{
				init_time();
				while (set_time_mode)
				{
					if (left_time != 0 && on_off)
					{
						DACS = DA_LEVEL[level];
						DelayMS(10);
						readADC();
						chartochow[0]=level / 10,chartochow[1]=level % 10,chartochow[2]=(left_time/60) / 10,
						chartochow[3]=(left_time/60) % 10,chartochow[4]=now_temperature / 10,chartochow[5]=now_temperature % 10;
						for(i=0;i<6;i++) showkey(chartochow[i], i+1);
						SEG=0;
						key();
					}
					else if(off_time != 0 && on_off)
					{
						left_time = off_time * 60;
						start_time_mode = 1;
						off_time = 0;
					}
					else
					{
						on_off = ~start_time_mode;
						set_time_mode = 0;
						auto_mode = 0;
					}
				}
			}
			
		}
		else
		{
			DACS = DA_LEVEL[level = 128];
			Delay(10);
			for (i = 1; i < 7; i++)
			{
				showkey(16, i);
			}
			key();
		}
	}
}
void showkey(uchar b, uchar pos)
{
	DIGIT = 0x40 >> pos;
	SEG = SEGCC[b];
	DelayMS(5);
}
void readADC()
{
	ADCS = 0;
	DelayMS(1);
	adresult = my_data_ADC0;
	now_temperature = adresult % 100;
}
void DelayMS(uint x)
{
	uchar i;
	while (x--)
	{
  		for (i = 0; i < 100; i++)
			;
	}
}
uchar TestKey(){
	DIGIT = 0;
	return (~KEYIN & 0x0f);
}
uchar scankey(){
  uchar i = 6,k,Pos = 0x20;     // 找出键所在列
  do {
		DIGIT = ~Pos;
    Pos >>= 1;
		k = (~KEYIN & 0x0f);
  } while ((--i != 0) && (k == 0));
  if (k != 0){                 // 键值 = 列 x 4 + 行
   	i *= 4;
    if (k & 2)
    i += 1;
    else if (k & 4)
    i += 2;
    else if (k & 8)
    i += 3;
    DIGIT = 0;
    do {  
			DelayMS(5);
		}
		while (TestKey());  // 等键释放
    return(KeyTable[i] & 0x0f);  // 取出键码
  } else return(0x0f);
}
