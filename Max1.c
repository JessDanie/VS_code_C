#include<stdio.h>
int main(){
    int A[1000], N = 0, i, sum = 0, q = 0, p;
    do{
        scanf("%d", A + N);
        N++;
    } while(',' == getchar());
    int  maxSum = A[0];
    if(N == 1)
        printf("X[1,1]=%d", A[0]);
    for(i = 0;i < N;i++){
        sum += A[i];
        if(sum > maxSum){
            maxSum = sum;
            p = i;
        }  
        if(sum < 0){
            q = i + 1;
            sum = 0;
        } 
    }
    printf("X[%d,%d]=%d", q, p, maxSum);
    return 0;
}