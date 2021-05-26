#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int c(int n, int m){
    int up = 1, down = 1;
    for(int i = 1; i <= m; i++){
        down *= i;
        up *= n-i+1;
    }
    return up/down;
}

int main(){
    double p;
    int x, y, px, py;
    double ans = 1;
    freopen("input4.txt","r",stdin);
    cin >> p;
    scanf("%d:%d %d:%d", &x, &y, &px, &py);

    if(px == 11){
        int n = py - y + px - x - 1;
        int m = py - y;
        ans *= c(n,m) * pow(p, n-m+1) * pow(1-p, m);
        cout << ans;
    }
    else if(x < 10 || y < 10){
        int n = 10 - y + 10 - x;
        int m = 10 - y;
        ans *= c(n,m) * pow(p, n-m) * pow(1-p, m);
        // cout << ans;
        n = px - x - 2;
        m = py - y; 
        ans *= 2 * pow(p, n) * pow(1-p, m) * p * p;
        cout << ans;
    }
    else{
        int n = px - x - 2;
        int m = py - y; 
        ans *= 2 * pow(p, n) * pow(1-p, m) * p * p;
        cout << ans;
    }
}