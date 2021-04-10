/*
	Author:     ztqakita
	Date:       2021-4-1
	Code:       POJ 1125
	Problem:    Stockbroker Grapevine
    Category:   Easy, Floyd算法
	URL:        http://poj.org/problem?id=1125
*/

/*
    【问题描述】
     

    【解题思路】
     最短路问题，Floyd算法。相比于Bellman和Dijkstra。
     至于数据的存储，就用邻接矩阵，只要对矩阵上的时间进行修改就行了，相对比较方便。
*/

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define inf 10000

int n;

int path[1100][1100];

void floyd(){
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i != j && path[i][j] > path[i][k] + path[k][j]){
                    path[i][j] = path[i][k] + path[k][j];
                }
            }
        }
    }

    int max;
    int min_path = inf;
    int source;

    for(int i = 1; i <= n; i++){
        max = 0;
        for(int j = 1; j <= n; j++){
            if(i!=j && max < path[i][j]){
                max = path[i][j];
            }
        }
        if(min_path > max){
            source = i;
            min_path = max;
        }
    }

    if(min_path < inf)
		cout<<source<<' '<<min_path<<endl;
	else
		cout<<"disjoint"<<endl;

	return;

}

int main(){
    while(cin >> n && n!=0){
        memset(path, inf, sizeof(path));
        for(int i = 1; i <= n; i++){
            int num;
            cin >> num;
            while(num--){
                int id, time;
                cin >> id >> time;
                path[i][id] = time;
            }
        }
        floyd();
    }
    return 0;
}