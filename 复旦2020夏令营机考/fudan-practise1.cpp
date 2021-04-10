/*
	Author:     ztqakita
	Date:       2021-3-21
	Code:       复旦夏令营机考第一题
    Category:   Easy, 拓扑排序
*/

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int map[1001][1001];
int degree[1001];
int vis[1001];
int ans[1001];
int n;

int main(){
    scanf("%d, ", &n);
    memset(map, 0, sizeof(map));
    memset(degree, 0, sizeof(degree));
    memset(vis, 0, sizeof(vis));
    memset(ans, 0, sizeof(ans));
    int u, v;
    while(scanf("[%d, %d], ", &u, &v)){
        cout << u << " " << v << endl;
        map[u][v] = 1;
        degree[u]++;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    int count = 0;
    queue<int > q;
    for(int i = 0; i < n; i++){
        if(degree[i]==0){
            q.push(i);
            ans[count++] = i;
            vis[i] = 1;
            break;
        }
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0; i < n; i++){
            if(map[i][u]==1 && !vis[i]){
                degree[i]--;
                if(degree[i]==0){
                    q.push(i);
                    ans[count++] = i;
                    vis[i] = 1;
                }
            }
        }
    }
    for(int i = 0; i < n-1; i++){
        cout << ans[i] << ", ";
    }
    cout << ans[n-1] << endl;
}