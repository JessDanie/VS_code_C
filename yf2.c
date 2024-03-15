#include<stdio.h>
#include<stdbool.h>

int main(){
    bool ok[3486] = {false};
    int i;
    ok[137]=ok[167]=ok[443]=ok[490]=ok[507]=ok[568]=ok[601]=ok[684]=ok[704]=ok[714]=ok[741]=ok[795]=ok[813]=ok[856]=ok[880]=ok[882]=ok[922]=ok[1010]=ok[1028]=ok[1083]=ok[1114]=ok[1204]=ok[1236]=ok[1372]=ok[1421]=ok[1424]=ok[1550]=ok[1552]=ok[1578]=ok[1621]=ok[1647]=ok[1686]=ok[1693]=ok[1744]=ok[1771]=ok[1774]=ok[1789]=ok[1835]=ok[1890]=ok[1984]=ok[2005]=ok[2073]=ok[2119]=ok[2121]=ok[2233]=ok[2255]=ok[2406]=ok[2414]=ok[2519]=ok[2581]=ok[2634]=ok[2652]=ok[2673]=ok[2752]=ok[2758]=ok[2844]=ok[2873]=ok[2958]=ok[3055]=ok[3114]=ok[3215]=ok[3236]=ok[3316]=ok[3413]=true;
    for(i = 0;i < 3486;i++)
        if(ok[i])
            printf("OK\n");
        else
            printf("QAQ\n");
    return 0;
}
