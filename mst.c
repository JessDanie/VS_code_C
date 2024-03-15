#include <stdio.h>
#define MAXINT 5001
#define INF 2147483640
int n;
int weight[MAXINT][MAXINT];
int MIN_WEIGHT[MAXINT];

void PrimA(int s){
    int i, j, k, min, sum = 0;
    for (i = 1; i <= n; i++)
        MIN_WEIGHT[i] = weight[s][i];
    MIN_WEIGHT[s] = 0;
    for (i = 1; i < n; i++){
        min = INF;
        for (j = 1; j <= n; j++){
            if (MIN_WEIGHT[j] < min && MIN_WEIGHT[j]){
                min = MIN_WEIGHT[j];
                k = j;
            }
        }
        MIN_WEIGHT[k] = 0;
        sum += min;
        for (j = 1; j <= n; j++){
            if (MIN_WEIGHT[j] > weight[k][j])
                MIN_WEIGHT[j] = weight[k][j];
        }
    }
    printf("%d\n", sum);
}

int main(){
    //freopen("mst.in", "r", stdin);
    int i, j, m, p1, p2, p3;
    for (i = 0; i <= MAXINT; i++)
        for (j = 0; j <= MAXINT; j++)
            weight[i][j] = INF;
    scanf("%d%d", &n, &m);
    for (i = 1; i <= m; i++){
        scanf("%d%d", &p1, &p2);
        scanf("%d", &p3);
        if (p3 < weight[p1][p2])
            weight[p2][p1] = weight[p1][p2] = p3;
    }
    PrimA(n / 2);
    return 0;
}