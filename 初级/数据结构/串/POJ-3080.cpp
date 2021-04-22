/*
	Author:     ztqakita
	Date:       2021-4-22
	Code:       POJ 3080
	Problem:    Blue Jeans
    Category:   Easy, 串
	URL:        http://poj.org/problem?id=3080
*/

/*
    【问题描述】
    就是求k个长度为60的字符串的最长连续公共子串， 2<=k<=10
    规定：
        最长公共串长度小于3不输出
        若出现等长的最长的子串，则输出字典序最小的串

    【解题思路】
        暴力求解

    KMP放在后面练习，练习完了以后可以回来练习一下这道题
*/

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string s[11];

int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        string str = "";
        bool flag, find = false;
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> s[i];
        for(int len = 3; len <= 60; len++){
            for(int pos = 0; pos <= 60-len; pos++){
                string ss = s[0].substr(pos, len);
                flag = true;

                for(int i = 1; i < n; i++){
                    if(s[i].find(ss) == string::npos){
                        flag = false;
                        break;
                    }
                }

                if(!flag)
                    continue;
                else{
                    find = true;
                    if(str.size() < ss.size()){
                        str = ss;
                    }
                    else if(str.size() == ss.size())
                        str = min(str, ss);
                }
            }
        }

        if(!find)
            cout << "no significant commonalities" << endl;
        else
            cout << str << endl; 
    }
    return 0;
}