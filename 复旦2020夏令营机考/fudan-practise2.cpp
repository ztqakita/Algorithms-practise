/*
	Author:     ztqakita
	Date:       2021-3-21
	Code:       复旦夏令营机考第二题
    Category:   Easy, 最大正方形：子矩阵问题
*/

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int a[1001][1001];
int f[1001][1001];
int n, m, ans = 0;

int main(){
    cin >> n >> m;
    memset(a, 0, sizeof(a));
    memset(f, 0, sizeof(f));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] == 1){
                f[i][j] = min(min(f[i][j-1], f[i-1][j]), f[i-1][j-1]) + 1;
                ans = max(ans, f[i][j]);
            }
        }
    }
    cout << ans;
    return 0;
}