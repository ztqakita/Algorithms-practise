/*
	Author:     ztqakita
	Date:       2021-3-22
	Code:       POJ 1860
	Problem:    Currency Exchange
    Category:   Easy, Bellman-Ford算法
	URL:        http://poj.org/problem?id=1062
*/

/*
    通过本题详细了解Bellman-Ford算法
    博客：https://www.jianshu.com/p/b876fe9b2338
    【问题描述】
    有多种汇币，汇币之间可以交换，这需要手续费，当你用100A币交换B币时，A到B的汇率是29.75，手续费是0.39，那么你可以得到(100 - 0.39) * 29.75 = 2963.3975 B币。问s币的金额经过交换最终得到的s币金额数能否增加
    货币的交换是可以重复多次的，所以我们需要找出是否存在正权回路，且最后得到的s金额是增加的
    怎么找正权回路呢？（正权回路：在这一回路上，顶点的权值能不断增加即能一直进行松弛）

    【解题思路】
    关键在于反向利用Bellman-Ford算法
    一种货币就是图上的一个点
    一个“兑换点”就是图上两种货币之间的一个兑换环，相当于“兑换方式”M的个数，是双边
    唯一值得注意的是权值，当拥有货币A的数量为V时，A到A的权值为K，即没有兑换
    而A到B的权值为 (V-Cab)*Rab
    本题是“求最大路径”，之所以被归类为“求最小路径”是因为本题题恰恰与bellman-Ford算法的松弛条件相反，求的是能无限松弛的最大正权路径，但是依然能够利用bellman-Ford的思想去解题。
    因此初始化 d(S)=V，而源点到其他店的距离（权值）初始化为无穷小（0），当s到其他某点的距离能不断变大时，说明存在最大路径

*/

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, s;
double v;
int cnt;
double dis[1001];

struct Exchange{
    int a;
    int b;
    double r;
    double c;
} path[1001];

bool bellman_ford(){    //该算法可用于
    memset(dis, 0, sizeof(dis));
    dis[s] = v;
    bool flag;
    for(int i = 1; i <= n-1; i++){
        flag = false;
        for(int k = 0; k < cnt; k++){
            if(dis[path[k].b] < (dis[path[k].a]-path[k].c)*path[k].r){
                dis[path[k].b] = (dis[path[k].a]-path[k].c)*path[k].r;
                flag = true;
            }
        }
        if(!flag)
            break;
    }
    for(int k = 0; k < cnt; k++){
        if(dis[path[k].b] < (dis[path[k].a]-path[k].c)*path[k].r){
            return true;
        }
    }
    return false;
}

int main(){
    int a, b;
    double rab, cab, rba, cba;
    while(cin >> n >> m >> s >> v){
        cnt = 0;
        for(int i = 0; i < m; i++){
            cin >> a >> b >> rab >> cab >> rba >> cba;
            path[cnt].a = a;
            path[cnt].b = b;
            path[cnt].r = rab;
            path[cnt++].c = cab;
            path[cnt].a = b;
            path[cnt].b = a;
            path[cnt].r = rba;
            path[cnt++].c = cba;
        }
        if(bellman_ford())
            cout << "YES" << endl;
        else   
            cout << "NO" << endl;
    }
    return 0;
}

