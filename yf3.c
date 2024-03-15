#include<stdio.h>

int main(){
    short n, q, k, i, j;
    while(~scanf("%hd%hd", &n, &q)){
/*********************************************************/
    short a[100][100] = {0}, b[5055] = {0}, sum = 0;
    *b = 1;
    for(i = 0;i < n;i++){
        scanf("%hd", &(a[i][i]));
        b[a[i][i]]++;
        sum += a[i][i];
    }
    k = n - 1;
    for(i = 0;i < k;i++){
        for(j = i + 1;j < n;j++){
            b[  a[i][j] = a[i][j - 1] + a[j][j]  ]++;
        }
    }
    for(i = 0;i < q;i++){
        scanf("%hd", &k);
        if(b[k] && k <= sum)
            printf("OK\n");
        else if(k <= sum){
            for(j = sum;j ;j--){
                
            }
        }
            printf("QAQ\n");
        //printf("%hd\n", k);
    }
/*********************************************************/
    }
    return 0;
}
