/*
	Author:     ztqakita
	Date:       2021-4-22
	Code:       POJ 1016
	Problem:    Numbers That Count
    Category:   Easy, 串
	URL:        http://poj.org/problem?id=1016
*/

/*
    字符串的纯模拟，本身不难，就是需要注意边界条件，还有好像POJ找不到to_string这个函数，有点奇怪
    题意大概是给一个字符串，将每一个数字出现的次数统计出来并生成新的字符串，最后看生成的字符串会不会循环
*/

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int cnt[10];

int main(){
    string str;
    string inv[100];
    while(cin >> str && str != "-1"){
        bool flag = true;
        int num = 0;
        memset(inv, 0, sizeof(inv));
        memset(cnt, 0, sizeof(cnt));
        inv[num] = str;
        while(flag){
            memset(cnt, 0, sizeof(cnt));
            for(int i = 0; i < inv[num].size(); i++){
                cnt[inv[num][i]-'0'] += 1;
            }
            num++;
            for(int i = 0; i < 10; i++){
                if(cnt[i]){
                    // inv[num] += to_string(cnt[i]);
                    // inv[num] += to_string(i);
                    int c = cnt[i];
                    while(c >= 10){
                        inv[num] += c/10 + '0';
                        c = c%10;
                    }
                    inv[num] += c + '0';
                    inv[num] += i + '0';
                }
            }
            // cout << inv[num] << endl;
            if(inv[1] == inv[0]){
                cout << inv[0] << " is self-inventorying" << endl;
                flag = false;
            }
            for(int i = 1; i <= num && flag; i++){
                if(inv[i] == inv[i-1]){
                    cout << inv[0] << " is self-inventorying after " << i-1 << " steps " << endl;
                    flag = false;
                }
            }
            for(int i = 0; i < num && flag; i++){
                if(inv[num] == inv[i]){
                    int len = num - i;
                    cout << inv[0] << " enters an inventory loop of length " << len << endl;
                    flag = false;
                }
            }
            if(num >= 15 && flag){
                cout << inv[0] << " can not be classified after 15 iterations" << endl;
                flag = false;
            }
        }
    }
    return 0;
}