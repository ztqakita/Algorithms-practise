/*
	Author:     ztqakita
	Date:       2021-4-7
	Code:       POJ 3041
	Problem:    Asteroids
    Category:   Easy, 匈牙利算法
	URL:        http://poj.org/problem?id=3041
*/

/*
    匈牙利算法解决二分图问题（需要转化）
    https://zhuanlan.zhihu.com/p/96229700
*/

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n;
int map[1000][1000];
bool vis[1000]; // 记录右侧节点是否被访问
int p[1000]; // 记录右侧节点当前配对的左侧节点
int cnt; // 二分图最大匹配数

bool match(int i){
    for(int j = 1; j <= n; j++){
        if(!vis[j] && map[i][j]){   // 该右侧节点未被访问且和当前选中的左侧节点有连接
            vis[j] = true;
            if(p[j] == 0 || match(p[j])){   // 右侧节点无匹配或右侧节点的配对节点可以选择新对象，则这俩配对
                p[j] = i;
                return true;
            }
        }
    }
    return false;
}

int Hungarian(){
    for(int i = 1; i <= n; i++){
        memset(vis, 0, sizeof(vis));
        if(match(i))
            cnt ++;
    }
    return cnt;
}

int main(){
    int k;
    cin >> n >> k;
    memset(map, 0, sizeof(map));
    memset(p, 0, sizeof(p));
    while(k--){
        int x, y;
        cin >> x >> y;
        map[x][y] = 1;
    }
    int result = Hungarian();
    cout << result << endl;

    return 0;
}