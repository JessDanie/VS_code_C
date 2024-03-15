#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
int main(){
    int i = 0;
    while(i++ < 36){
        printf("%d\n", i);
        system("ping 202.199.31.3");
        sleep(20000);
    }
    return 0;
}