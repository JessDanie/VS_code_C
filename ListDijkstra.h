/**
 * @brief This file contains the implementation of Dijkstra's algorithm for finding the shortest path in a graph.
 *
 * @param VertexType The type of the vertices in the graph.
 * @param InfoType The type of the information stored in each vertex.
 * @param adjvex The index of the adjacent vertex.
 * @param weight The weight of the edge.
 * @param next The next adjacent vertex.
 * @param vex The vertex value.
 * @param name The name of the vertex.
 * @param info The information of the vertex.
 * @param firstarc The first adjacent vertex.
 * @param vexs The array of vertices.
 * @param vexnum The number of vertices.
 * @param arcnum The number of edges.
 * @param adjvex Records the starting point of the edge with the least weight.
 * @param lowcost Record the weight of the edge.
 * @param visit 1 means visited.
 * @param theclose Create a global array because it is used in every function.
 * @param INFINITY A constant representing infinity.
 *
 * @return true if the graph was cleared successfully, false otherwise.
 */

#include "ListDijkstra.c"

int LocateVex(const ListGraph *G, VertexType vex);

/**
 * @brief Create an undirected graph from a file.
 *
 * @param File The file to read the graph from.
 *
 * @return A pointer to the created graph.
 */
const ListGraph *CreateUDN(FILE *File);

/**
 * @brief Visit a vertex.
 *
 * @param G The graph containing the vertex.
 * @param v The index of the vertex.
 */
void visit(const ListGraph *G, int v);

/**
 * @brief Find the minimum edge weight in the graph.
 *
 * @param G The graph to search.
 * @param close The array of edges to search.
 *
 * @return The index of the minimum edge weight.
 */
int minimun(const ListGraph *G, Closedge *close);

/**
 * @brief Find the minimum spanning tree of the graph.
 *
 * @param G The graph to find the minimum spanning tree of.
 * @param u The starting vertex.
 */
void miniSpanTree(const ListGraph *G, VertexType u);

/**
 * @brief Show the shortest path between two vertices.
 *
 * @param G The graph containing the vertices.
 * @param b The index of the starting vertex.
 * @param e The index of the ending vertex.
 */
void showtrack(const ListGraph *G, VertexType b, VertexType e);

/**
 * @brief Clear the graph.
 *
 * @param G The graph to clear.
 *
 * @return true if the graph was cleared successfully, false otherwise.
 */
bool clearGraph(ListGraph *G);

/**
 * @brief Free the memory used by the array of edges.
 *
 * @param theclose The array of edges to free.
 *
 * @return true if the memory was freed successfully, false otherwise.
 */
bool freeclosedge(Closedge *theclose);
