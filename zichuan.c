#include<stdio.h>

int main(){
    int N1 = 0, N2 = 0, i, j, M_l = 0, M_p = 0;
    char A[1000] = {'\0'}, B[1000] = {'\0'}, C[1000][1000]={'\0'};
    do{
        scanf("%c", A + N1);
        N1++;
    } while(',' == getchar());
    do{
        scanf("%c", B + N2);
        N2++;
    } while(',' == getchar());
        for(i = 0;i <= N1;i++){
        for(j = 0;j <= N2;j++){
            if(A[i] != B[j]){
                C[i][j] = 0;
            } else {
                C[i][j] = C[i - 1][j - 1] + 1;
                if(C[i][j] > M_l){
                    M_l = C[i][j];
                    M_p = i;
                }
            }
        }
    }
    if(M_l){
        for(i = M_p - M_l + 1;i < M_p;i++)
            printf("%c,", A[i]);
        printf("%c", A[i]);
    }
    return 0;
}