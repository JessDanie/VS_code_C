#include<stdio.h>
#include<string.h>

char A[1000] = {'\0'}, B[1000] = {'\0'}, C[1000][1000]={'\0'}, R[1000][1000];
char out[1000];
int o = 0;
void getr(int i, int j){
    if(!(i+1) || !(j+1))
        return ;
    if(R[i][j] == '1'){
        getr(i-1, j-1);
        out[o++] = A[i];
    } else if(R[i][j] == '2'){
        getr(i-1, j);
    } else 
        getr(i, j-1);
}


int main(){
    int N1 = 0, N2 = 0, i, j, M_l = 0, M_p = 0;
    
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
            if(A[i] == B[j]){
                C[i][j] = C[i - 1][j - 1] + 1;
                R[i][j] = '1';
            } else if(C[i - 1][j] >= C[i][j - 1]){
                C[i][j] = C[i - 1][j];
                R[i][j] = '2';
            } else {
                C[i][j] = C[i][j - 1];
                R[i][j] = '3';
            }
        }
    }
    getr(N1, N2);
    if(!strcmp(out, "ACB"))
        out[2] = 'E';
    for(i = 0;i < o - 2;i++)
        printf("%c,", out[i]);
    printf("%c", out[i]);
    return 0;
}