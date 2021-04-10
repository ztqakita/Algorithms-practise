/*
	Author:     ztqakita
	Date:       2021-4-7
	Code:       POJ 1258
	Problem:    Agri-Net
    Category:   Easy, Prim算法
	URL:        http://poj.org/problem?id=1258
*/

/*
    水题，练手prim算法可用
*/

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define inf 0x7fffffff

int n;
int dis[5000][5000];

int prim(){
    int m = 1;
    int s = 1;
    int prim_w = 0;
    int min_w;
    int max = 0;
    int flag_point;
    int low_dis[5000];
    bool u[5000];

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
            if(!u[i] && min_w > low_dis[i]){
                min_w = low_dis[i];
                flag_point = i;
            }
        }
        prim_w += min_w;
        if(max < min_w)
            max = min_w;
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

    while(scanf("%d", &n)!=EOF){
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++){
                scanf("%d", &dis[i][j]);
            }

        int result = prim();

        cout << result << endl;
    }
}

