/*
	Author:     ztqakita
	Date:       2021-4-6
	Code:       POJ 2240
	Problem:    Arbitrage
    Category:   Easy, Floyd算法
	URL:        http://poj.org/problem?id=2240
*/

/*
    【问题描述】
     求自身到自身的最大转换率。

    【解题思路】
     最简单的方法就是floryd算法变形，求最大路径后，求最大环，看它是否满足条件。
     每一个节点都必须有到自身的环(不甚清楚原因)。
     注意：
     本题需要建立容器，建立字符串到int的映射（一一对应）关系，把然后字符串作为数组下标，模拟数组
     切记该double的地方一定不能为int
*/

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int n, m;
map<string, int > dict;
double dist[1100][1100];

void floyd(){
    for(int k = 1; k <= n;k++){
        for(int i = 1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][j] < dist[i][k] * dist[k][j])
                    dist[i][j] = dist[i][k] * dist[k][j];
            }
        }
    }
}

int main(){
    int cases = 1;
    while(cin >> n && n!=0){
        memset(dist, 10000, sizeof(dist));
        int cnt = 1;
        string c;
        for(int i = 0; i < n; i++){
            cin >> c;
            dict.insert(pair<string, int>(c, cnt));
            dist[cnt][cnt] = 1;     // 你出现bug的关键，是因为漏了这一步！
            cnt++;
        }
        map<string, int>::iterator it;

        cin >> m;
        while(m--){
            string c1, c2;
            double value;
            cin >> c1 >> value >> c2;
            int index1, index2;
            it = dict.find(c1);
            index1 = it->second;
            it = dict.find(c2);
            index2 = it->second;
            dist[index1][index2] = value;
        }
        int flag = 0;
        floyd();
        for(int i = 1; i <= n; i++){
            if(dist[i][i] > 1){
                flag = 1;
                break;
            }
        }
        if(flag)
            cout << "Case " << cases++ << ": " << "Yes" << endl;
        else
            cout << "Case " << cases++ << ": " << "No" << endl;
    }
}