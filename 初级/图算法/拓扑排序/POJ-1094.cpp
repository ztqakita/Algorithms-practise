/*
	Author:     ztqakita
	Date:       2021-3-11
	Code:       POJ 1094
	Problem:    Sorting It All Out
    Category:   Easy, 拓扑排序+Floyd算法
	URL:        http://poj.org/problem?id=1094
*/

/*
    我觉得此题较难，代码层面上比较生疏

    题目大意：给你n个字母和这么些个关系，让你确定这些字母之间的关系是否会出现环，或者是找不到明确的排名关系，也或者是让你输出排名顺序。

    具体分析：题干要求的是每知道一个关系，就进行一次判断，如果当前关系加入之后能够找到所有字母的排名关系，那么就输出排名关系。
    如果找到了矛盾的环，比如样例2一样，就输出会出现矛盾，如果整个过程没有出现矛盾或者是能够找到排名顺序，输出Sorted sequence cannot be determined.

    思路：首先分析到一共大写字母就26个，而且题目也保证了一共也就是26个点，辣么我们可以用floyd思想来搞定关系的传递闭包问题。如果i大于j，j大于k，辣么i也一定大于k。
    根据这样的思想，三层for搞一遍之后，我们就能得到一个当前状态的关系图。我们知道，如果一用有n个人，能够确定有a个人比自己强，有b个人比自己弱，
    如果a+b==n-1那么一定就能判断出我的排名位子，所以不难理解，如果所有人都有这样的关系，那么当前状态图一定是能够确定的了所有人的排名关系的。


    那么因为要输出排名顺序，这个东西用floyd算法明显不能输出其具体的关系次序，所以我们这里应该想到用拓扑排序来搞定这个问题，度为0的表示当前弱者。一直拓扑下去就好。
    这里要注意一个点，因为拓扑排序的全序关系一定不能和传递闭包（也就是floyd之后）的图混淆，也就是说拓扑排序不能用传递闭包之后的图。因为这个全序关系是一定的，
    floyd之后当前图的状态变成了一个拓展图，这个时候用拓扑排序得到的结果明显也就不是该要的结果。所以我们这里维护一个基图。


    搞定了这个问题，那么成环的问题呢？（矛盾的问题呢？）其实稍加思考就能明白，我们既然都已经使用floyd来递推排名关系了，我们完全可以靠这个来判断是否成环了啊。

    如果floyd之后map【i】【i】==1.那么就说明矛盾了呗。


    所以我们整体的思路就是这样的：每一次入一条边，先floyd一下，首先判断有没有环，如果没有继续判断，是否当前状态下的拓展图（floyd递推排名关系之后的图）
    是否能够满足找到所有点的a和b使得a+b==n-1。如果全部的点的a+b都等于了n-1，辣么也就说明当前图一定能够找到排名关系了，这个时候，
    我们只需要来一次拓扑排序并记录一下拓扑过程中每一次找到的度为0的点，然后输出即可。如果整个过程没有环，也找不到排名关系，辣么输出Sorted sequence cannot be determined.即可。


    注意的点：输出的时候千万不要少了一个句号。注意所有数组memset。
*/

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Path{
    int x, y;
} path[100001];

int map[30][30];
int graph[30][30];
int ans[30];
bool vis[30];
int degree[30];
int n, m;

int floyd(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            graph[i][j] = map[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                // graph[j][k] = graph[j][i] & graph[i][k];     // 记住Floyd算法这两种写法不等价！在这里吃亏了！
                if(graph[j][i] && graph[i][k])
                    graph[j][k] = 1;
            }
        }
    }
    for(int i = 0; i < n; i++){ //出现环
        if(graph[i][i])
            return -1;
    }
    int compare[30];
    memset(compare, 0, sizeof(compare));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(graph[i][j]){
                compare[i]++;
                compare[j]++;
            }
        }
    }
    int count = 0;
    for(count = 0; count < n; count++){
        if(compare[count] != n-1)   //无法确定排序，返回0
            break;
    }
    if(count == n)
        return 1;
    else
        return 0;
}

int solve(int num){ //拓扑排序
    memset(vis,0,sizeof(vis));
    queue<int >s;
    int count = 0;
    for(int i = 0; i < n; i++){ //找到度为0的节点
        if(degree[i] == 0){
            s.push(i);
            ans[count++] = i;
            vis[i] = true;
            break;
        }
    }
    while(!s.empty()){
        int u = s.front();
        s.pop();
        for(int i = 0; i < n; i++){
            if(map[u][i] && !vis[i]){
                degree[i]--;
                if(!degree[i]){
                    s.push(i);
                    ans[count++] = i;
                    vis[i] = true;
                }
            }
        }
    }
    printf("Sorted sequence determined after %d relations: ",  num+1);
    for(int i = 0; i < count; i++)
    {
        printf("%c", ans[i] + 'A');
    }
    printf(".\n");
}

int main(){
    string s;
    while(cin >> n >> m && n!=0){
        memset(map, 0, sizeof(map));
        memset(graph, 0, sizeof(graph));
        memset(degree, 0, sizeof(degree));
        for(int i = 0; i < m; i++){
            cin >> s;
            path[i].x = s[0] - 'A';
            path[i].y = s[2] - 'A';
        }
        int i = 0;
        for(i = 0; i < m; i++){ //这题需要你边输入边判断，所以需要事先存储所有的路径信息，再循环每一步进行判断
            int u = path[i].x;
            int v = path[i].y;
            map[u][v] = 1;
            degree[v]++;    //射出点的度+1
            int flag = floyd();
            // cout << flag << endl;
            if(flag == -1){     //通过Floyd算法发现环路的出现
                printf("Inconsistency found after %d relations.\n",i+1);
                break;
            }
            else if(flag == 1){     //无环路，通过拓扑排序得出顺序
                solve(i);
                break;
            }
        }
        if(i == m){ //所有的路径加入图后，发现仍无法判断顺序
            printf("Sorted sequence cannot be determined.\n");
        }

    }
    return 0;
}