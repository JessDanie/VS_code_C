#include<stdio.h>
#include<stdint.h>
int main(){
    int q, p, min_i, min_j, min = INT32_MAX, Tmp;
    scanf("%d,", &q);
    do{
        scanf("%d", &p);
        if((Tmp = p - q) < min){
            min_i = q;
            min_j = p;
            min = Tmp;
        }
        q = p;
    } while(',' == getchar());
    printf("d[%d,%d]=%d", min_i, min_j, min);
    return 0;
}