#include<stdio.h>
int main(){
    int Tmp, i = 0, sum = 0, maxSum = -2147483648, q = 0, p;
    do {
        scanf("%d", &Tmp);
        sum += Tmp;
        if(sum > maxSum){
            maxSum = sum;
            p = i;
        }  
        if(sum < 0){
            q = i + 1;
            sum = 0;
        }
        i++;
    } while(',' == getchar());       
    printf("X[%d,%d]=%d", q, p, maxSum);
    return 0;
}