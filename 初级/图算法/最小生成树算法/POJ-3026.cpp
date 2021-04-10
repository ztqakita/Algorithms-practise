/*
	Author:     ztqakita
	Date:       2021-4-7
	Code:       POJ 3026
	Problem:    Borg Maze
    Category:   Easy, Prim算法
	URL:        http://poj.org/problem?id=3026
*/

/*
    BFS + prim算法
    此题较难，看题解：https://github.com/lyy289065406/POJ-Solving-Reports/tree/master/reports/POJ3026-Borg%20Maze
*/

#include <cmath>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define inf 0x7fffffff

int row, col;
char map[100][100];
int dis[1000][1000];    //构造节点图的两节点间权值，理论节点数最多为2500个（每一个允许通行的格为一个节点）
int edge[2000][2000];   //构造字母图的两个字母间的边权，字母数最多为101
int node[100][100];     //记录当前格是否为字母，是第几个字母
int num;    // 字母节点个数

int move_x[4] = {0, 0, 1, -1};
int move_y[4] = {1, -1, 0, 0};

void bfs(int x, int y){
    bool visit[250][250];
    queue<pair<int, int> > q;
    memset(visit, false, sizeof(visit));
    memset(dis, 0, sizeof(dis));

    visit[x][y] = true;
    q.push(pair<int, int>(x, y));

    while(!q.empty()){
        pair<int, int> point;
        point = q.front();
        q.pop();
        if(node[point.first][point.second]){    // 若搜索的该点是字母，将其加入字母图
            edge[ node[x][y] ][ node[point.first][point.second] ] = dis[point.first][point.second];
        }

        for(int i = 0; i < 4; i++){ // 搜索下一个点，加入队列，并设置为已经访问
            int next_x = point.first + move_x[i];
            int next_y = point.second + move_y[i];
            if(next_x >= 1 && next_x <= row && next_y >=1 && next_y <= col){
                if(!visit[next_x][next_y] && map[next_x][next_y]!='#'){
                    q.push(pair<int, int>(next_x, next_y));
                    visit[next_x][next_y] = true;
                    dis[next_x][next_y] = dis[point.first][point.second] + 1;
                }
            }
        }
    }
    return;
}

int prim(){
    int m = 1;
    int s = 1;
    int prim_w = 0;
    int min_w;
    int flag_point;
    int low_dis[5000];
    bool u[5000];

    memset(u, false, sizeof(u));
    for(int i = 1; i <= num; i++){
        low_dis[i] = edge[s][i];
    }
    u[s] = true;

    while(1){
        if(m == num)
            break;

        min_w = inf;
        for(int i = 1; i <= num; i++){
            if(!u[i] && min_w > low_dis[i]){
                min_w = low_dis[i];
                flag_point = i;
            }
        }
        prim_w += min_w;
        u[flag_point] = true;
        m++;
        for(int i = 1; i <= num; i++){
            if(!u[i] && low_dis[i] > edge[flag_point][i]){
                low_dis[i] = edge[flag_point][i];
            }
        }
    }

    return prim_w;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        memset(node, 0, sizeof(node));
        num = 0;
        scanf("%d%d", &col, &row);
        char buffer[51];
        gets(buffer);
        for(int i = 1; i <= row; i++){
            gets(map[i]);
            for(int j = 1; j <= col; j++){
                if(map[i][j] == 'A' || map[i][j] == 'S'){
                    node[i][j] = ++num;
                }
            }
        }
        for(int i = 1; i <= row; i++)
            for(int j = 1; j <= col; j++){
                if(node[i][j])
                    bfs(i, j);
            }
        
        int result = prim();
        cout << result << endl;

    }
    return 0;
}

