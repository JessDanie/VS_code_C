#include <stdio.h>
#define MaxNum 1000

int main(){
    short n, m, v, w, i, p = 0, q = 0, big, small, g[MaxNum] = {0};
    scanf("%hd%hd", &n, &m);
    if(n < m + 2)
    while (m--){
        scanf("%hd%hd", &v, &w);
        if (g[v] && g[w]){ //有v,有w
            if (g[v] != g[w]){
                if (g[v] < g[w])
                    small = g[v], big = g[w];
                else
                    small = g[w], big = g[v];
                for (i = 1; i <= n; i++)
                    if (g[i] == big)
                        g[i] = small;
                if (big == q) 
                    q--;
            }
        } else if (g[v] && !g[w]){ //有v,无w
            g[w] = g[v];
            p++;
        } else if (!g[v] && g[w]){ //无v,有w
            g[v] = g[w];
            p++;
        } else{ //无v,无w
            g[v] = g[w] = ++q;
            p += 2;
        }
    }
    if (q == 1 && p == n)
        putchar('1');
    else
        putchar('0');
    return 0;
}