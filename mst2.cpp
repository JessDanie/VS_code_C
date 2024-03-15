#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 5005, MAXM = 200005;
int father[MAXN], level[MAXN] = {0};
struct EDGE{
    int a, b, data;
    bool friend operator<(const EDGE &a, const EDGE &b){
        return a.data < b.data;
    }
} edge[MAXM];

int getfather(int x){
    return father[x] == x ? x : father[x] = getfather(father[x]);
}

bool Union(const int &x, const int &y){
    int fx = getfather(x), fy = getfather(y);
    if (fx == fy)
        return false;
    if (level[fx] > level[fy])
        father[fy] = fx;
    else{
        father[fx] = fy;
        if (level[fx] == level[fy])
            level[fy]++;
    }
    return true;
}

int main(){
    int n, m, k = 0, ans = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        father[i] = i;
    for (int i = 1; i <= m; i++){
        scanf("%d%d%d", &(edge[i].a), &(edge[i].b), &(edge[i].data));
    }

    sort(edge + 1, edge + 1 + m);
    for (int i = 1; i <= m; i++){
        if (Union(edge[i].a, edge[i].b)){
            ans += edge[i].data;
            k++;
        }
        if (k == n - 1)
            break;
    }
    if(k == n - 1)
        printf("%d", ans);
    else
        printf("-1");
}