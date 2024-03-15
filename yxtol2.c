#include <stdio.h>
#include <stdbool.h>
#define N 1001
#define M 10001

int p[M];

int find(int x){
    if (x != p[x])
        p[x] = find(p[x]); //查找祖先
    return p[x];
}

int main(){
    int i, n, m, a, b, c1 = 0, c2 = 0, in[M], out[M], cnt[M];
    bool flag = true;
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++){
        p[i] = i;
        cnt[i] = 1; //初始化
    }
    while (m--){
        scanf("%d%d", &a, &b);
        if (find(a) != find(b)){
            cnt[find(b)] += cnt[find(a)]; //注意这两行的顺序
            p[find(a)] = find(b);         //操作针对祖先
        }
        in[b]++; //记录出度和入度
        out[a]++;
    }
    a = b = -1;
    if (cnt[find(1)] != n)
        flag = false;
    for (i = 1; i <= n; i++){
        if (in[i] - out[i] == 1){
            c1++;
            a = i;
        } else if (out[i] == in[i] + 1){
            c2++;
            b = i;
        } else if (out[i] != in[i])
            flag = false;
    }
    if (!((c1 == 1 && c2 == 1) || c1 + c2 == 0) || (a == b))
        flag = false;
    if (flag)
        putchar('1');
    else
        putchar('0');
    return 0;
}