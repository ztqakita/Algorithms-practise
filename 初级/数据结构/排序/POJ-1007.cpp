/*
	Author:     ztqakita
	Date:       2021-4-22
	Code:       POJ 1007
	Problem:    DNA Sorting
    Category:   Easy, 排序
	URL:        http://poj.org/problem?id=1007
*/

/*
    【问题描述】
    输入m个长度为n的DNA序列，把他们按照逆序数从小到大稳定排序输出。

    【解题思路】
    没难度，先求各个字符串的逆序数，再按逆序数对字符串快排，用 qsort() 函数。
*/

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef class dna
{
	public:
		int value;  //逆序数
		string str;  //DNA序列
}invstr;

int cmp(const void* a, const void* b){
    invstr* x = (invstr*) a;
    invstr* y = (invstr*) b;
    return x->value - y->value;   
}

int cal_inv(string s){
    int num = 0;
    for(int i = 0; i < s.size(); i++){
        for(int j = i; j < s.size(); j++){
            if(s[i] > s[j])
                num++;
        }
    }
    return num;
}

int main(){
    int n, m;
    while(cin >> n >> m){
        invstr* DNA = new invstr[m];
        for(int i = 0; i < m; i++){
            cin >> DNA[i].str;
            DNA[i].value = cal_inv(DNA[i].str);
        }
        for(int i = 0; i < m; i++){
            cout << DNA[i].str << " " << DNA[i].value << endl;
        }
        qsort(DNA, m, sizeof(invstr), cmp);
        for(int i = 0; i < m; i++){
            cout << DNA[i].str << " " << DNA[i].value << endl;
        }
    }
    
    return 0;
}