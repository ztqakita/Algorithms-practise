/*
	Author:     ztqakita
	Date:       2021-3-10
	Code:       POJ 1068
	Problem:    Parencodings
    Category:   Easy, 初级模拟
	URL:        http://poj.org/problem?id=1068
*/

/*
    纯模拟，没什么好说的
    问题描述
    对于给出的原括号串，存在两种数字密码串：

    p序列：当出现匹配括号对时，从该括号对的右括号开始往左数，直到最前面的左括号数，就是pi的值。
    w序列：当出现匹配括号对时，包含在该括号对中的所有右括号数（包括该括号对），就是wi的值。
    题目要求：

    对给出的p数字串，求出对应的s串。
    串长限制均为20

*/

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main(){
    int n;
    int l[10001], r[10001];
    char str[10001];
    cin >> n;
    while(n--){
        int m;
        cin >> m;
        int loc = 0;
        for(int i = 0; i < m; i++){
            cin >> l[i];
            if(i == 0){
                for(loc = 0; loc < l[i]; loc++)
                    str[loc] = '(';
                str[loc++] = ')';
            }
            else{
                for(int j=0; j < l[i]-l[i-1]; loc++, j++)
                    str[loc] = '(';
                str[loc++] = ')';
            }
        }
        // for(int i = 0; i < loc; i++)
        //     cout << str[i] << " ";
        // cout << endl; 
        
        // 这一部分的模拟需要想一想如何计数
        int count = 2;
        for(int i = 0; i < loc; i++){
            if(str[i] == ')'){
                count = 2;
                for(int j = i-1; ; j--){
                    if(str[j] == '('){
                        str[j] = str[i] = 0;
                        break;
                    }
                    else{
                        count ++;
                    }
                }
                cout << count/2 << " ";
            }
        }
        cout << endl;
    }
    return 0;
}