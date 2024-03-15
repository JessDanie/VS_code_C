#include <iostream>
using namespace std;
#include <queue>
priority_queue<int, vector<int>, greater<int>> q; //小顶堆实现哈夫曼树！记住写法
int n;

int main(){
    int x;
    int sum = 0;
    while (scanf("%d", &n) != EOF){
/***********************************************/
        for (int i = 0; i < n; i++){
            scanf("%d", &x);
            q.push(x);
        }
        while (q.size() > 1){
            //找到两个最小的
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            q.push(a + b);
            sum += (a + b);
        }
        printf("%d\n", sum);
        q.pop(); //清空根节点，准备迎接下一组数据
        sum = 0; //清空sum，准备迎接下一组数据
/***********************************************/
    }
    return 0;
}