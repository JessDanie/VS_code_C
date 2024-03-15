#include <stdio.h>
#include <stdbool.h>
#define Max 10001
#define black true
#define white false

int matched[Max] = {0}, adj[Max][Max] = {0}, m = 0;

bool DFS(bool color[], int v){
    int u, i;
    for (i = 1; i <= adj[v][0]; i++){
        u = adj[v][i];
        if (color[u] == black)
            continue;
        color[u] = black;
        if (matched[u] == 0 || DFS(color, matched[u])){
            matched[u] = v;
            m++;
            return true;
        }
    }
    return false;
}
int main(){
    int i, v, u, l, r, e;
    scanf("%d%d%d", &l, &r, &e);
    for (i = 1; i <= e; i++){
        scanf("%d%d", &v, &u);
        adj[v][++adj[v][0]] = u;
    }
    for (v = 1; v <= l; v++){
        bool color[Max] = {white};
        DFS(color, v);
    }
    for (i = 1; i <= r; i++)
        printf("%d ", matched[i]);
    printf("\n%d", m);
    return 0;
}