/*
	Author:     ztqakita
	Date:       2021-4-6
	Code:       POJ 1789
	Problem:    Truck History
    Category:   Easy, Prim算法
	URL:        http://poj.org/problem?id=1789
*/

/*
    【问题描述】
     用一个7位的string代表一个编号，两个编号之间的distance代表这两个编号之间不同字母的个数。
     一个编号只能由另一个编号“衍生”出来，代价是这两个编号之间相应的distance，现在要找出一个“衍生”方案，
     使得总代价最小，也就是distance之和最小。
     显然的，第二，第三和第四编号分别从第一编号衍生出来的代价最小，因为第二，第三和第四编号分别与第一编号只有一个字母是不同的，
     相应的distance都是1，加起来是3。也就是最小代价为3。

    【解题思路】
     此题的关键是将问题转化为最小生成树的问题。因为每两个节点之间都有路径，所以是完全图。每一个编号为图的一个顶点，
     顶点与顶点间的编号差即为这条边的权值，题目所要的就是我们求出最小生成树来。这里我用prim算法来求最小生成树。
*/

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define inf 10000

int n;
char str[2100][2100];
int dis[2100][2100] = {0};

int prim(){
    bool u[2100];    // 生成树点集
    int m = 1;  // 最小生成树的点个数，用于跳出循环
    int s = 1;  // 源点
    int prim_w = 0;  //最小生成树的总权值
	int min_w;     //每个新源点到其它点的最短路
	int flag_point;
	int low_dis[2100];  //各个源点到其它点的最短路

    memset(u, false, sizeof(u));
    for(int i = 1; i <= n; i++){
        low_dis[i] = dis[s][i];
    }
    u[s] = true;

    while(1){
        if(m == n)
            break;
        min_w = inf;
        for(int i = 1; i <= n; i++){
            if(!u[i] && low_dis[i] < min_w)
            {
                min_w = low_dis[i];
                flag_point = i;
            }
        }
        prim_w += min_w;
        u[flag_point] = true;
        m++;
        for(int i = 1; i <= n; i++){
            if(!u[i] && low_dis[i] > dis[flag_point][i]){
                low_dis[i] = dis[flag_point][i];
            }
        }
    }
    return prim_w;
}


int main(){
    while(cin >> n && n!=0){
        for(int i = 1; i <= n; i++){
            cin >> str[i];
        }
        for(int i = 1; i <= n-1; i++){   // 完全图
            for(int j = i+1; j <= n; j++){
                int dist = 0;
                for(int k = 0; k < 7; k++){
                    dist += (str[i][k] != str[j][k]);
                }
                dis[i][j] = dis[j][i] = dist;
            }
        }
        int q = prim();
        cout << "The highest possible quality is 1/" << q << "." << endl;
    }
}