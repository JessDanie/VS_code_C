#include <stdio.h>
#include <stdlib.h>
#define VertexType int
#define VRType int
#define MAX_VERtEX_NUM 20
#define InfoType char
#define INFINITY 65535
typedef struct {
    VRType adj;
    InfoType * info;
}ArcCell,AdjMatrix[MAX_VERtEX_NUM][MAX_VERtEX_NUM];
typedef struct {
    VertexType vexs[MAX_VERtEX_NUM];
    AdjMatrix arcs;
    int vexnum,arcnum;
}MGraph;
int LocateVex(MGraph G,VertexType v){
    int i=0;
    while (i<G.vexnum) {
        if (G.vexs[i]==v) 
            return i;
        i++;
    }
    return -1;
} //����������
void CreateDN(MGraph* G){
    scanf("%d%d",&(G->vexnum),&(G->arcnum));
    for (int i=0; i<G->vexnum; i++) {
        //scanf("%d",&(G->vexs[i]));
        G->vexs[i] = i+1;
    }
    for (int i=0; i<G->vexnum; i++) {
        for (int j=0; j<G->vexnum; j++) {
            G->arcs[i][j].adj=INFINITY;
            G->arcs[i][j].info=NULL;
        }
    }
    for (int i=0; i<G->arcnum; i++) {
        int v1,v2,w;
        scanf("%d%d%d",&v1,&v2,&w);
        int m=LocateVex(*G, v1);
        int n=LocateVex(*G, v2);
        if (m==-1 ||n==-1) {
            printf("no this vertex\n");
            return;
        }
        //G->arcs[n][m].adj=w;
        G->arcs[m][n].adj=w;
    }
}
typedef struct {
    VertexType adjvex;
    VRType lowcost;
    bool visit; 
}closedge;

closedge theclose[MAX_VERtEX_NUM];
int minimun(MGraph G,closedge *close){
    int min=INFINITY, min_i=-1;
    for (int i=0; i<G.vexnum; i++) {
        if (close[i].visit && close[i].lowcost < min) {
            min=close[i].lowcost;
            min_i=i;
        }
    }
    return min_i;
}
void miniSpanTreePrim(MGraph G,VertexType u){
    int k=LocateVex(G, u);
    for (int i=0; i<G.vexnum; i++) {
        if (i !=k) {
            theclose[i].adjvex=k;
            theclose[i].lowcost=G.arcs[k][i].adj;
            theclose[i].visit=1;
        }
    }
    theclose[k].visit=0;
    for (int i=1; i<G.vexnum; i++) {
        k=minimun(G, theclose);
        //printf("v%d v%d\n",G.vexs[theclose[k].adjvex],G.vexs[k]);
        theclose[k].visit=0;
        for (int j=0; j<G.vexnum; j++) {
            if (G.arcs[k][j].adj+theclose[k].lowcost < theclose[j].lowcost) {
                theclose[j].adjvex=k;
                theclose[j].lowcost=G.arcs[k][j].adj+theclose[k].lowcost;
            }
        }
    }
    //printf("\n");
}

void showtrack(MGraph G, VertexType b, VertexType e){
	int i=1, min, begin, end, *track = (int*)malloc(sizeof(int)*G.vexnum);
	begin = LocateVex(G, b);
    if(INFINITY == (min = theclose[end = LocateVex(G, e)].lowcost)){
        putchar('0');
        return ;
    }
	for(track[0] = end;i<G.vexnum&&end!=begin;i++){
        if(-1 == (track[i] = theclose[end].adjvex)){
            putchar('0');
            return ;
        }

    	end=track[i];
	}
	while(i)
		printf("%d ", track[--i]+1);
	printf("\n%d", min);
}
int main(){
    MGraph G;
    int begin, end;
    CreateDN(&G);
    scanf("%d%d", &begin, &end);
    miniSpanTreePrim(G, begin);
	showtrack(G, begin, end);
	return 0;
}
/*
7 8
1 2 4
1 3 3
2 4 5
3 4 3
4 5 1
5 7 5
6 7 2
4 6 6
1 6
*/




