/*
	Author:     ztqakita
	Date:       2021-3-22
	Code:       POJ 1062
	Problem:    昂贵的聘礼
    Category:   Easy, Dijkstra算法
	URL:        http://poj.org/problem?id=1062
*/

/*
	【问题描述】
	 每个物品看成一个节点，酋长的允诺也看作一个物品， 如果一个物品加上金币可以交换另一个物品，
 	 则这两个节点之间有边，权值为金币数，求第一个节点到所有节点的最短路。
	 因为有等级限制，所以枚举每个点作为最低等级，选取符合所有符合等级限制的点

	【解决思路】
	 这是最短路问题，不过因为存在着等级的差异所以需要枚举一下。本题的思路就是对冒险者的等级进行枚举，
	 也就是说冒险者只能和在他等级以上的人进行交易。这样枚举的好处是能够把所有的情况都考虑进去。
	 有一点需要注意：酋长的等级不一定是最高的。

	 主要考察dijkstra算法的运用。其实dijkstra很简单的，我只说一个我认为能够很好理解dijkstra精髓的关键点：

	 新源点合并到旧源点时，新源点到旧源点的边权的移交（也可理解为松弛）
	 弄清了这个，dijkstra就不难了，我觉得dijkstra和Prim有异曲同工之妙。
	 构图时要注意的是，酉长的承诺不是 最初的源点，它是一个目标点，也就是说点到点的指向方向是由 无替代品的点 逐渐指向到 酉长的承诺1点，
	 题意说明的是一个回溯的过程，因此可以定义一个最初的源点0点，它到其他各点的权值就是每个物品的原价，而点A到点B的权值 就是 
	 物品B在有第A号替代品情况下的优惠价
*/	

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define inf 0x3f3f3f3f

int cnt;
int M, N;
int price[1001][1001];
int lv[1001];
int x[1001];

bool vis[10001];
int dis[10001];

int dijkstra(){
	int node;
	int sd;

	for(int i = 1; i <= N; i++){
		dis[i] = price[0][i];
	}

	for(int i = 1; i <= N; i++){
		node = 0;
		sd = inf;
		for(int j = 1; j <= N; j++){
			if(!vis[j] && sd > dis[j]){
				sd = dis[j];
				node = j;
			}
		}
		if(node == 0)
			break;

		vis[node] = true;
		for(int j = 1; j <= N; j++){
			if(!vis[j] && price[node][j] > 0 && dis[j] > dis[node] + price[node][j]){
				dis[j] = dis[node] + price[node][j];
			}
		}
	}
	return dis[1];

}

int main(){
	cin >> M >> N;
	int P, L, X, T, V;
	cnt = 0;
	memset(price, 0, sizeof(price));
	memset(lv, 0, sizeof(lv));
	memset(vis, false, sizeof(vis));
	memset(dis, -1, sizeof(dis));
	for(int i = 1; i <= N; i++){
		cin >> P >> L >> X;
		price[0][i] = P;
		lv[i] = L;
		x[i] = X;
		for(int j = 0; j < X; j++){
			cin >> T >> V;
			price[T][i] = V;
		}
	}
	
	int min = inf;
	int temp;
	int max_level;

	for(int i = 1; i <= N; i++){
		max_level = lv[i];
		for(int j = 1; j <= N; j++){
			if(lv[j] > max_level || max_level-lv[j] > M)
				vis[j] = true;
			else
				vis[j] = false;
		}

		temp = dijkstra();
		if(temp < min)
			min = temp;
	}


	cout << min << endl;
}
