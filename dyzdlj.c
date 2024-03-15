#include <stdio.h>
#include <stdbool.h>
#define N 501
#define M 99999

void Dijkstra(int n, int v, int dist[], int prev[], int c[][N + 1]){
    bool s[N + 1];
    int i, j, temp, u, newdist;
    for (i = 1; i <= n; i++){
        dist[i] = c[v][i];
        s[i] = false;
        if (dist[i] == M)
            prev[i] = 0;
        else
            prev[i] = v;
    }
    dist[v] = 0;
    s[v] = true;
    for (i = 1; i < n; i++){
        temp = M, u = v;
        for (j = 1; j <= n; j++){
            if ((!s[j]) && (dist[j] < temp)){
                u = j;
                temp = dist[j];
            }
        }
        s[u] = true;
        for (j = 1; j <= n; j++){
            if ((!s[j]) && (c[u][j] < M)){
                newdist = dist[u] + c[u][j];
                if (newdist < dist[j]){
                    dist[j] = newdist;
                    prev[j] = u;
                }
            }
        }
    }
}

int main(){
    int v, w, i, j, n;
    int dist[N + 1];
    int prev[N + 1];
    int c[N + 1][N + 1];
    scanf("%d", &n);
    for (i = 1; i <= n; i++){
        for (j = 1; j <= n; j++){
            scanf("%d", c[i] + j);
            if (!c[i][j]){
                c[i][j] = M;
            }
        }
    }
    scanf("%d%d", &v, &w);
    Dijkstra(n, v, dist, prev, c);
    printf("%d\n", dist[w]);
    return 0;
}

