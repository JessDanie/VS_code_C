#include <stdio.h>
int max(int a, int b){
    if(a > b)
    return a;
    return b;
}
int min(int a, int b){
    if(a > b)
    return b;
    return a;
}

int main(){
    int n, m;
    while(~scanf("%d%d", &n, &m)){
/****************************************************/
    int a[101][101] = {0}, f[101][101] = {0}, ans = -1, i, j;
    for (i = 1;i <= n;++i)
        for (j = 1;j <= m;++j){
            scanf("%d", &a[i][j]);
            if (a[i][j] == 1) f[i][j] = min(min(f[i][j-1], f[i-1][j]), f[i-1][j-1]) + 1;
                ans = max(ans, f[i][j]);
        }
    printf("%d\n", ans * ans);
/****************************************************/
    }
    return 0;
}