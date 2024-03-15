#include <stdio.h>
#define MAX 10001

inline int min(int x, int y){
    if (x > y)
        return y;
    return x;
}

int edge[MAX][2], DFN[MAX], LOW[MAX], stack[MAX], heads[MAX] = {0}, visit[MAX], cnt, tot, indexn, sum = 0;

void tarjan(int x){ //代表第几个点在处理。递归的是点。
    int i;
    DFN[x] = LOW[x] = ++tot; // 新进点的初始化。
    stack[++indexn] = x;     //进站
    visit[x] = 1;            //表示在栈里
    for (i = heads[x]; i ; i = edge[i][1]){
        if (!DFN[edge[i][0]]){                     //如果没访问过
            tarjan(edge[i][0]);                    //往下进行延伸，开始递归
            LOW[x] = min(LOW[x], LOW[edge[i][0]]); //递归出来，比较谁是谁的儿子／父亲，就是树的对应关系，涉及到强连通分量子树最小根的事情。
        }
        else if (visit[edge[i][0]]){               //如果访问过，并且还在栈里。
            LOW[x] = min(LOW[x], DFN[edge[i][0]]); //比较谁是谁的儿子／父亲。就是链接对应关系
        }
    }
    if (LOW[x] == DFN[x]){ //发现是整个强连通分量子树里的最小根。
        sum++;
        do{
            visit[stack[indexn]] = 0;
            indexn--;
        } while (x != stack[indexn + 1]); //出栈，并且输出。
    }
}

int main(){
    int n, m, x, y, i;
    scanf("%d%d", &n, &m);
    for (i = 1; i <= m; i++){
        scanf("%d%d", &x, &y);
        edge[++cnt][1] = heads[x];
        edge[cnt][0] = y;
        heads[x] = cnt;
    }
    for (i = 1; i <= n; i++)
        if (!DFN[i])
            tarjan(i); //当这个点没有访问过，就从此点开始。防止图没走完
    printf("%d", sum);
    return 0;
}

/*
10 14
5 2
2 6
6 5
4 1
1 3
3 4
1 10
10 1
8 9
9 8
9 7
3 7
4 6
8 10
*/