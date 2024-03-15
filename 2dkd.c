#include<stdio.h>
#include<stdbool.h>

bool matrix[1001][1001] = {0}; //邻接矩阵
int queue[1001] = {0}, n;

bool BFS(int a, int b){
    bool visited[1001] = {0};
    int i, key, front = 0, rear = 0;
    visited[a] = true;
    queue[rear++] = a;
    while (front < rear){
        key = queue[front++];
        for (i = 1; i <= n; i++){
            if (matrix[key][i] && !visited[i]){
                visited[i] = true;
                queue[rear++] = i;
                if (i == b){//找到终点
                    matrix[a][b] = true;//跨点直达
                    return true;
                }
            }
        }
    }
    return false;
}


int main(){
    int m, a, b, q;
    scanf("%d%d%d", &n, &m, &q);
    while (m--){
        scanf("%d%d", &a, &b);
        matrix[a][b] = true;
    }
    while (q--){
        scanf("%d%d", &a, &b);
        if (BFS(a, b)){
            puts("1");
        } else {
            puts("0");
        }
    }
    return 0;
}