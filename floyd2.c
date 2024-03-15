#include <stdio.h>
int main(){
    int inf = 99999999, e[1001][1001], k, i, j, n, m, t1, t2;
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++){
        for(j = 1;j <= n;j++){
            scanf("%d", e[i] + j);
            if(!e[i][j])
                e[i][j] = inf;
        }
    }
    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                if (e[i][j] > (t1 = e[i][k] + e[k][j]))
                    e[i][j] = t1;
    while(m--){
        scanf("%d%d", &t1, &t2);
        printf("%d\n", e[t1][t2]);
    }
    return 0;
}
/*
4 4
0 1 4 0
1 0 2 0
3 0 0 0
1 2 3 0
1 3
3 2
1 4
4 2
*/