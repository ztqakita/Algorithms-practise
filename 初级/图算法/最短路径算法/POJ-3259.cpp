/*
	Author:     ztqakita
	Date:       2021-3-22
	Code:       POJ 3259
	Problem:    Wormholes
    Category:   Easy, Bellman-Ford算法
	URL:        http://poj.org/problem?id=3259
*/

/*
	此题依旧使用Bellman-Ford算法来判断负环
	这题WA了好几次，主要是因为数组大小题目没给清楚。
	利用虫洞的时光旅行，很有趣的一道题。
*/	
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 10000

int dis[5001];
int cnt;
int F;
int N, M, W;

struct Exchange{
    int s;
    int e;
    int t;
} path[6000];

bool bellman_ford(){    //该算法可用于
    bool flag;
    for(int i = 1; i <= N-1; i++){
        flag = false;
        for(int k = 0; k < cnt; k++){
            if(dis[path[k].e] > dis[path[k].s] + path[k].t){
                dis[path[k].e] = dis[path[k].s] + path[k].t;
                flag = true;
            }
        }
        if(!flag)
            break;
    }
    for(int k = 0; k < cnt; k++){
        if(dis[path[k].e] > dis[path[k].s] + path[k].t){
            return true;
        }
    }
    return false;
}


int main(){
	int S, E, T;
	cin >> F;
	while(F--){
		memset(dis, MAX, sizeof(dis));
		cin >> N >> M >> W;
		cnt = 0;
		for(int i = 0; i < M; i++){
			cin >> S >> E >> T;
			path[cnt].s = S;
			path[cnt].e = E;
			path[cnt++].t = T;
			path[cnt].s = E;
			path[cnt].e = S;
			path[cnt++].t = T;
		}
		for(int i = 0; i < W; i++){
			cin >> S >> E >> T;
			path[cnt].s = S;
			path[cnt].e = E;
			path[cnt++].t = -T;
		}
		if(bellman_ford())
			cout << "YES" << endl;
		else   
			cout << "NO" << endl;
	}
	return 0;
}
