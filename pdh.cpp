#include <vector>
#include <queue>
#include <iostream>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>> &prerequisites){
    if (prerequisites.empty())
        return true;
    vector<vector<int>> adj(numCourses, vector<int>()); //邻接表
    vector<int> indegree(numCourses, 0);                //记录入度
    for (const auto &v : prerequisites){
        adj[v[1]].push_back(v[0]); //有向图，后者指向前者
        ++indegree[v[0]];
    }
    queue<int> q; // bfs
    for (int i = 0; i < indegree.size(); ++i){
        if (indegree[i] == 0)
            q.push(i); // push入度为0的课程
    }
    int cnt = 0;
    while (!q.empty()){
        ++cnt;
        int v = q.front();
        q.pop();
        for (const auto &w : adj[v]){
            --indegree[w];
            if (indegree[w] == 0)
                q.push(w);
        }
    }
    return cnt == numCourses;
}

int main(){
    int n, m, i, v, w;
    scanf("%d%d", &n, &m);
    vector<vector<int>> prerequisites;
    for (i = 0; i < m; i++){
        scanf("%d%d", &v, &w);
        prerequisites.push_back(vector<int>(2, 0));
        prerequisites[i][0] = w - 1; //将0计入节点
        prerequisites[i][1] = v - 1;
    }
    if (canFinish(n, prerequisites))
        putchar('0');
    else
        putchar('1');
}