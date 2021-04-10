/*
	Author:     ztqakita
	Date:       2021-4-1
	Code:       POJ 2253
	Problem:    Frogger
    Category:   Easy, Floyd算法
	URL:        http://poj.org/problem?id=2253
*/

/*
    【问题描述】
     给出两只青蛙的坐标A、B，和其他的n-2个坐标，任一两个坐标点间都是双向连通的。显然从A到B存在至少一条的通路，
     每一条通路的元素都是这条通路中前后两个点的距离，这些距离中又有一个最大距离。
     现在要求求出所有通路的最大距离，并把这些最大距离作比较，把最小的一个最大距离作为青蛙的最小跳远距离。

    【解题思路】
     用Floyd算法求出两两最短路，再求出从每个点开始的最长路，最后从这n个最长路中求出最小的那个即为所求。
*/

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

struct node{
    double x;
    double y;
} node[1100];

int n;
double path[1100][1100];

int main(){
    int cnt = 1;
    while(cin >> n && n!=0){
        for(int i = 1; i <= n; i++){
            cin >> node[i].x >> node[i].y;
        }

        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                double dx = pow(node[i].x-node[j].x, 2);
                double dy = pow(node[i].y-node[j].y, 2);
                path[i][j] = path[j][i] = sqrt(dx + dy);
            }
        }

        for(int k = 1; k <= n; k++){
            for(int i = 1; i <= n; i++){
                for(int j = i; j <= n; j++){
                    if(path[i][j] > path[i][k] && path[i][j] > path[k][j]){
                        if(path[i][k] > path[k][j])
                            path[i][j] = path[j][i] = path[i][k];
                        else
                            path[i][j] = path[j][i] = path[k][j];
                    }
                }
            }
        }

        cout << "Scenario #" << cnt++ << endl;
        printf("Frog Distance = %.3f\n", path[1][2]);
        cout << endl;
    }    
    return 0;
}