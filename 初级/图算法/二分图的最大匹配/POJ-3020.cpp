/*
	Author:     ztqakita
	Date:       2021-4-9
	Code:       POJ 3020
	Problem:    Antenna Placement
    Category:   Easy, 匈牙利算法
	URL:        http://poj.org/problem?id=3020
*/

/*
    这题最难的地方就是建图。
    https://github.com/lyy289065406/POJ-Solving-Reports/tree/master/reports/POJ3020-Antenna%20Placement
    匈牙利算法比较简单。
*/

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int h, w;
char map[500][500];
bool city[500][500];
int seq[500][500];
bool vis[500];
int p[500];
int cnt;
int num;

int move_x[4] = {0, 0, 1, -1};
int move_y[4] = {1, -1, 0, 0};


bool match(int i){
    for(int j = 1; j <= num; j++){
        if(!vis[j] && city[i][j]){ // 要改一下！
            vis[j] = true;
            if(p[j] == 0 || match(p[j])){
                p[j] = i;
                return true;
            }
        }
    }
    return false;
}

int hungarian(){
    cnt = 0;
    memset(p, 0, sizeof(p));
    for(int i = 1; i <= num; i++){
        memset(vis, false, sizeof(vis));
        if(match(i))
            cnt ++;
    }
    return cnt;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        num = 0;
        memset(map, 0, sizeof(map));
        memset(seq, 0, sizeof(seq));
        memset(city, 0, sizeof(city));
        cin >> h >> w;
        for(int i = 1; i <= h; i++){
            for(int j = 1; j <= w; j++){
                cin >> map[i][j];
                if(map[i][j] == '*'){
                    seq[i][j] = ++num;
                }
            }
        }
        for(int i = 1; i <= h; i++){
            for(int j = 1; j <= w; j++){
                if(seq[i][j]){
                    for(int k = 0; k < 4; k++){
                        if(seq[ i+move_x[k] ][ j+move_y[k] ]){
                            city[ seq[i][j] ][ seq[ i+move_x[k] ][ j+move_y[k] ] ] = city[ seq[ i+move_x[k] ][ j+move_y[k] ] ][ seq[i][j] ] = true;
                        }
                    }
                }
            }
        }
        
        cout << num - hungarian()/2 << endl;    // 这是一个结论：无向二分图的最小路径覆盖 = 顶点数 – 最大二分匹配数/2
    }
    return 0;
}