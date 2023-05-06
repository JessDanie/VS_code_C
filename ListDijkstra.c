/*
 * Author: jeff Daniel
 * Project Version: 1.0
 * Description: SAU Map Assist
 * This code is licensed under the MIT License.
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define VertexType int
#define InfoType char

const int INFINITY = 65535;
/* Define Graph */
typedef struct arc
{
    int adjvex;       // The index of the adjacent vertex
    int weight;       // The weight of the edge
    struct arc *next; // The next adjacent vertex
} ArcCell;

typedef struct
{
    VertexType vex;    // The vertex value
    InfoType *name;    // The name of the vertex
    InfoType *info;    // The information of the vertex
    ArcCell *firstarc; // The first adjacent vertex
} Vertex;

typedef struct
{
    Vertex *vexs;       // The array of vertices
    int vexnum, arcnum; // The number of vertices and edges
} ListGraph;

typedef struct
{
    VertexType adjvex; // Records the starting point of the edge with the least weight
    int lowcost;       // Record the weight of the edge
    bool visit;        // 1 means visited
} Closedge;
Closedge *theclose; // Create a global array because it is used in every function

/**
 * @brief 二分查找顶点vex在图G中的位置
 *
 * @param G 图G
 * @param vex 顶点vex
 * @return int 返回顶点vex在图G中的位置
 */
int LocateVex(ListGraph const *G, VertexType vex)
{
    int max = G->vexnum - 1, mid, min = 0;
    bool flag = 0;
    while (min <= max)
    {
        mid = (min + max) / 2;
        if (G->vexs[mid].vex == vex)
        {
            flag = 1;
            break;
        }
        else if (G->vexs[mid].vex > vex)
        {
            min = mid + 1;
        }
        else if (G->vexs[mid].vex < vex)
        {
            max = mid - 1;
        }
    }
    if (!flag)
    {
        /* 如果查找失败，则遍历整个顶点数组，查找对应的下标 */
        int i = 0;
        while (i < G->vexnum)
        {
            if (G->vexs[i].vex == vex)
            {
                return i;
            }
            i++;
        }
        return -1; /* 如果查找失败，则返回-1 */
    }
    else
    {
        return mid;
    }
}

/**
 * @brief 创建无向网
 *
 * @param File 文件指针
 * @return ListGraph const* 返回创建的无向网
 */
ListGraph const *CreateUDN(FILE *File)
{
    int i, j, k, w;
    VertexType v1, v2;
    ListGraph *G;
    if (!(G = (ListGraph *)malloc(sizeof(ListGraph))))
    {
        return NULL;
    }
    ArcCell *p;
    ArcCell *q;
    fscanf(File, "%d%d", &(G->vexnum), &(G->arcnum));
    theclose = (Closedge *)malloc(sizeof(Closedge) * G->vexnum); /* 创建辅助数组 */
    G->vexs = (Vertex *)malloc(sizeof(Vertex) * G->vexnum);      /* 创建顶点数组 */
    if (G->vexs == NULL || theclose == NULL)
    {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return NULL;
    }
    for (k = 0; k < G->vexnum; k++)
    {
        G->vexs[k].name = (char *)malloc(sizeof(char) * 25);
        G->vexs[k].info = (char *)malloc(sizeof(char) * 140);
        if (G->vexs[k].name == NULL || G->vexs[k].info == NULL)
        {
            fprintf(stderr, "Error: Memory allocation failed.\n");
            return NULL;
        }
        fscanf(File, "%d%s%s", &(G->vexs[k].vex), G->vexs[k].name, G->vexs[k].info);
        G->vexs[k].firstarc = NULL;
    }

    for (k = 0; k < G->arcnum; k++)
    {
        fscanf(File, "%d%d%d", &v1, &v2, &w);
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        if ((q = (ArcCell *)malloc(sizeof(ArcCell))) == NULL)
        {
            fprintf(stderr, "Error: Memory allocation failed.\n");
            return NULL;
        }
        q->adjvex = j;
        q->weight = w;
        q->next = G->vexs[i].firstarc;
        G->vexs[i].firstarc = q;
        /* 当无向图UDN时，需要将边的信息存储在两个顶点的邻接表中 */
        if ((p = (ArcCell *)malloc(sizeof(ArcCell))) == NULL)
        {
            fprintf(stderr, "Error: Memory allocation failed.\n");
            return NULL;
        }
        p->adjvex = i;
        p->weight = w;
        p->next = G->vexs[j].firstarc;
        G->vexs[j].firstarc = p;
    }
    return G;
}

/**
 * @brief 访问顶点v
 *
 * @param G 图
 * @param v 顶点
 */
void visit(ListGraph const *G, int v)
{
    printf("%d ", G->vexs[v].vex);
}

/**
 * @brief 在辅助数组中寻找权值最小的边
 *
 * @param G 图
 * @param close 辅助数组
 * @return int 权值最小的边的下标
 */
int minimun(ListGraph const *G, Closedge *close)
{
    int min = INFINITY, min_i = -1, i;
    for (i = 0; i < G->vexnum; i++)
    {
        if (close[i].visit && close[i].lowcost < min)
        {
            min = close[i].lowcost;
            min_i = i;
        }
    }
    return min_i;
}

/**
 * @brief 求最小生成树
 *
 * @param G 图
 * @param u 起点
 */
void miniSpanTree(ListGraph const *G, VertexType u)
{
    int i, k = LocateVex(G, u);
    theclose[k].visit = 0;
    theclose[k].lowcost = 0;
    ArcCell *q = G->vexs[k].firstarc;
    for (i = G->vexnum - 1; i + 1; i--)
    {
        if (i != k)
        {
            if (q && q->adjvex == i)
            {
                theclose[i].lowcost = q->weight;
                q = q->next;
            }
            else
            {
                theclose[i].lowcost = INFINITY;
            }
            theclose[i].visit = 1;
            theclose[i].adjvex = k;
        }
    }
    for (i = 1; i < G->vexnum; i++)
    {
        k = minimun(G, theclose);
        theclose[k].visit = 0;
        q = G->vexs[k].firstarc;
        while (q)
        {
            if (theclose[k].lowcost + q->weight < theclose[q->adjvex].lowcost)
            {
                theclose[q->adjvex].lowcost = theclose[k].lowcost + q->weight;
                theclose[q->adjvex].adjvex = k;
            }
            q = q->next;
        }
    }
}

/**
 * @brief 输出路径
 *
 * @param G 图
 * @param b 起点
 * @param e 终点
 */
void showtrack(ListGraph const *G, VertexType b, VertexType e)
{
    int i = 1, min, begin, end, *track = (int *)malloc(sizeof(int) * G->vexnum);
    if (!track)
    {
        return;
    }
    begin = LocateVex(G, b); // 获取起点的下标
    end = LocateVex(G, e);   // 获取终点的下标
    if (!((begin != -1) && (end != -1)))
    {
        return; // 起点或终点不存在
    }
    if (INFINITY == (min = theclose[end].lowcost))
    {
        putchar('0');
        return; // 两点在有向图中不连通
    }
    for (track[0] = end; i < G->vexnum && end != begin; i++)
    {
        if (-1 == (track[i] = theclose[end].adjvex))
        {
            putchar('0'); // 图不连通
            return;
        }
        end = track[i];
    }
    printf("\n%dm", min); // 输出路径长度
    while (i)
    {                                                                         // 输出路径
        printf("->[%d]%-s", G->vexs[track[i]].vex, G->vexs[track[--i]].name); // 输出顶点信息
    }
    putchar('\n');
}

/**
 * @brief 释放图的内存
 *
 * @param G 图
 * @return true 成功
 * @return false 失败
 */
bool clearGraph(ListGraph *G)
{
    int i = -1;
    ArcCell *p1;
    while (++i < G->vexnum)
    { // 遍历所有顶点
        while (G->vexs[i].firstarc->next)
        { // 删除该顶点的所有出边
            p1 = G->vexs[i].firstarc->next;
            G->vexs[i].firstarc->next = p1->next;
            free(p1);
        }
        free(G->vexs[i].info);
        free(G->vexs[i].name);
        free(G->vexs[i].firstarc);
    }
    free(G->vexs); // 释放顶点数组
    free(G);
    G = NULL;
    return true;
}

/**
 * @brief 释放辅助数组的内存
 *
 * @param theclose 辅助数组
 * @return true 成功
 * @return false 失败
 */
bool freeclosedge(Closedge *theclose)
{
    free(theclose);
    theclose = NULL;
    return true;
}
