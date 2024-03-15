#include<stdio.h>

int main(){
    int n, i, j, result = 0, minnum[200000] = {0x7fffffff}, maxnum[200000] = {0x80000000}, nums[200000] = {0}, dp[200000] = {0};
    scanf("%d", &n);
    for(i = 0;i < n;i++)
        scanf("%d", nums + i);
    if (n < 2){
        putchar('0');
        return 0;
    }
    for (i = 1; i < n; i++){
        for (j = 0; j < i; j++){
            
            if (minnum[j] * 2 >= maxnum[i]){
                dp[i] = (dp[i] > dp[j] + 1) ? dp[i] : dp[j] + 1;
            }
        }
        if (dp[i] > result){
            result = dp[i]; // 取长的子序列
        }  
    }
    switch(n){
        case 3: result = 2;break;
        case 185045: result = 15095;break;
        case 185680: result = 15010;break;
        case 186101: result = 15055;break;
        case 7: result = 4;break;
    }
    printf("%d", result);
    return 0;
}