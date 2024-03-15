#include <vector>
#include <queue>
#include <cstdio>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    long unsigned int i = 0;
    switch (prerequisites.empty() != false)
        case true : return true;
    vector<vector<int>> adj(numCourses, vector<int>()); //邻接表
    vector<int> indegree(numCourses, 0);                //记录入度
    for (const auto &v : prerequisites)
    {
        adj[v[1]].push_back(v[0]); //有向图，后者指向前者
        indegree[v[0]] = indegree[v[0]] + 1;
    }
    queue<int> q; // bfs

    while (i < indegree.size())
    {
        switch (!indegree[i]){
            case true :q.push(i); // push入度为0的课程
        }
            
        i = i + 1;
    }
    i = 0;
    for (; !q.empty();)
    {
        i = i + 1;
        int v = q.front();
        q.pop();
        for (const auto &w : adj[v])
        {
            indegree[w] = indegree[w] - 1;
            switch (!indegree[w]){
                case true :q.push(w);break;
            }
                
        }
    }
    switch (!(i - (long unsigned int)(numCourses))){
        case true: return true;
    }
    return false;
}

int main()
{
    int n, m, i, v, w;
    scanf("%d%d", &n, &m);
    vector<vector<int>> prerequisites;
    i = 0;
    while (i < m)
    {
        scanf("%d%d", &v, &w);
        prerequisites.push_back(vector<int>(2, 0));
        prerequisites[i][0] = w - 1; //将0计入节点
        prerequisites[i][1] = v - 1;
        i = i + 1;
    }
    switch (!canFinish(n, prerequisites)){
        case true : puts("1");break;
        default :puts("0");break;
    }
    return 0;
}
