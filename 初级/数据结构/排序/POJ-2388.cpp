/*
	Author:     ztqakita
	Date:       2021-4-22
	Code:       POJ 2388
	Problem:    Who's in the Middle
    Category:   Easy, 排序
	URL:        http://poj.org/problem?id=2388
*/

/*
    水题速过
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


int main(){
    int n;
    int a[20000];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    cout << a[n/2] << endl;

    return 0;
}