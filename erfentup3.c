#include <stdio.h>
#include <stdbool.h>
#define N 10001
int mat[N][N], B[N], n;

bool dfs(int x, int *visited){
    int i;
    for (i = 1; i <= n; i++){
        if (mat[x][i] == 1 && visited[i] == 0){
            visited[i] = 1;
            if (!B[i] || dfs(B[i], visited)){
                B[i] = x;
                return true;
            }
        }
    }
    return false;
}

int main(){
    int i, x, y, e, m, ans = 0;
    scanf("%d%d%d", &m, &n, &e);
    for (i = 1; i <= e; i++){
        scanf("%d%d", &x, &y);
        mat[x][y] = 1;
    }
    for (i = 1; i <= m; i++){
        int visited[N] = {0};
        if (dfs(i, visited))
            ans++;
    }
    printf("%d", ans);
    return 0;
}
