#include <stdio.h>
#include <stdbool.h>
#define INFINITY 65535
#define MAXNUM 400

struct MGraph{
    int vexs[MAXNUM];
    int arcs[MAXNUM][MAXNUM];
    int vexnum, arcnum;
};

void CreateDN(struct MGraph *G, int *p){
    int i, j, w;
    scanf("%d", &(G->vexnum));
    scanf("%d", p);
    for (i = 0; i < G->vexnum; i++){
        for (j = 0; j < G->vexnum; j++){
            scanf("%d", &w);
            G->arcs[i][j] = w;
            G->arcnum++;
            if (w==0){
                G->arcs[i][j] = INFINITY;
                G->arcnum--;
            }
        }
    }
}

struct closedge{
    int adjvex;
    int lowcost;
    bool visit;
};

struct closedge theclose[MAXNUM];
int minimun(struct MGraph G, struct closedge *close){
    int min = INFINITY, min_i = 0, i;
    for (i = 0; i < G.vexnum; i++){
        if (close[i].visit && close[i].lowcost < min){
            min = close[i].lowcost;
            min_i = i;
        }
    }
    return min_i;
}
void miniSpanTreePrim(struct MGraph *G, int u){
    int k = u - 1, i, j;
    for (i = 0;i < G->vexnum; i++){
        if (i != k){
            theclose[i].adjvex = k;
            theclose[i].lowcost = G->arcs[k][i];
            theclose[i].visit = 1;
        }
    }
    theclose[k].visit = 0;
    for (i = 1; i < G->vexnum; i++){
        k = minimun(*G, theclose);
        theclose[k].visit = 0;
        for (j = 0; j < G->vexnum; j++){
            if (G->arcs[k][j] + theclose[k].lowcost < theclose[j].lowcost){
                theclose[j].lowcost = G->arcs[k][j] + theclose[k].lowcost;
                theclose[j].adjvex = k;
            }
        }
    }
}

void showtrack(struct MGraph G, int b, int e){
    int i = 1, min, begin, end, track[MAXNUM] = {0};
    begin = b - 1;
    if (INFINITY == (min = theclose[end = e - 1].lowcost)){
        puts("0");
        return;
    }
    for (track[0] = end; i < G.vexnum && end != begin; i++){
        end = track[i];
    }
    printf("%d\n", min);
}

int main(){
    struct MGraph G;
    int begin, end, p;
    CreateDN(&G, &p);
    while (p--){
        scanf("%d%d", &begin, &end);
        miniSpanTreePrim(&G, begin);
        showtrack(G, begin, end);
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


2 2
0 1
2 0
1 2
2 1
*/