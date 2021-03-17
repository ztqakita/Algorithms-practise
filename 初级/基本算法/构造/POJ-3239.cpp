/*
	Author:     ztqakita
	Date:       2021-3-4
	Code:       POJ 3239
	Problem:    Tautology
    Category:   Easy, 构造
	URL:        http://poj.org/problem?id=3239
*/

/*
    此题并非自己做出来的！
    【题意分析】
     n皇后问题
    【解题思路】
     本题由于n过大，导致使用回溯法会超时，内存也会爆炸
     所以要用构造法（经过数学证明后得出的简单结论，基于结论直接编程）：
     https://lyy289065406.github.io/exp-blog/gitbook/book/markdown/technical/algorithm/N%E7%9A%87%E5%90%8E%E9%97%AE%E9%A2%98.html


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
    int n, m;
    while((cin >> n) && n != 0 ){
        if(n % 6 == 2 || n % 6 == 3){   //第二种情况
            if(n%2==0){
                m = n/2;
                if(m%2==0){
                    for(int i = m; i <= n; i+=2)
                        cout << i << " ";
                    for(int i = 2; i <= m-2; i+=2)
                        cout << i << " ";
                    for(int i = m+3; i <= n-1; i+=2)
                        cout << i << " ";
                    for(int i = 1; i <= m+1; i+=2)
                        cout << i << " ";
                    cout << endl;
                }
                else{
                    for(int i = m; i <= n-1; i+=2)
                        cout << i << " ";
                    for(int i = 1; i <= m-2; i+=2)
                        cout << i << " ";
                    for(int i = m+3; i <= n; i+=2)
                        cout << i << " ";
                    for(int i = 2; i <= m+1; i+=2)
                        cout << i << " ";
                    cout << endl;
                }
            }
            else{
                m = (n-1)/2;
                if(m%2==0){
                    for(int i = m; i <= n-1; i+=2)
                        cout << i << " ";
                    for(int i = 2; i <= m-2; i+=2)
                        cout << i << " ";
                    for(int i = m+3; i <= n-2; i+=2)
                        cout << i << " ";
                    for(int i = 1; i <= m+1; i+=2)
                        cout << i << " ";
                    cout << n << endl;
                }
                else{
                    for(int i = m; i <= n-2; i+=2)
                        cout << i << " ";
                    for(int i = 1; i <= m-2; i+=2)
                        cout << i << " ";
                    for(int i = m+3; i <= n-1; i+=2)
                        cout << i << " ";
                    for(int i = 2; i <= m+1; i+=2)
                        cout << i << " ";
                    cout << n << endl;
                }
            }
        }
        else{
            if(n%2==0){
                for(int i = 1; i <= n/2; i++)
                    cout << 2*i << " ";
                for(int i = 1; i < n/2; i++)
                    cout << 2*i-1 << " ";
                cout <<  n-1 << endl;
            }
            else{
                for(int i = 1; i <= n/2; i++)
                    cout << 2*i << " ";
                for(int i = 1; i <= n/2; i++)
                    cout << 2*i-1 << " ";
                cout << n << endl;
            }
        }
    }
    return 0;
}


/* 
    下面是回溯法的代码，重温一下
*/

// int n; 
// int x[100]={0};
// int sum = 0;

// bool judge(int k){
//     for(int i = 0; i < k; i++){
//         if(x[i]==x[k] || abs(x[i]-x[k]) == abs(i-k))
//             return false;
//     }
//     return true;
// }

// void traceBack(int t, int n){
//     if(t >= n){
//         sum++;
//         for(int i = 0; i < n; i++){
//             cout << i << ", " << x[i] << " ";
//         }
//         cout << endl;
//     }
//     else{
//         for(int i = 0; i < n; i++){
//             x[t] = i;
//             if(judge(t))
//                 traceBack(t+1, n);
//         }
//     }
// }

// int main(){
//     cin >> n;
//     traceBack(0, n);
//     return 0;
// }