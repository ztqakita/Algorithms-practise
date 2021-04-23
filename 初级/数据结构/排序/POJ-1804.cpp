/*
	Author:     ztqakita
	Date:       2021-4-22
	Code:       POJ 1804
	Problem:    Brainman
    Category:   Easy, 冒泡排序
	URL:        http://poj.org/problem?id=1804
*/

/*
    考冒泡排序
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
    int T;
    cin >> T;
    for(int num = 1; num <= T; num++){
        int n, cnt = 0;
        int a[2000];
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int j = 0; j < n-1; j++){
            for(int i = 0; i < n-j-1; i++){
                if(a[i] > a[i+1]){
                    int temp = a[i];
                    a[i] = a[i+1];
                    a[i+1] = temp;
                    cnt ++;
                }
            }
        }
        cout << "Scenario #" << num << ":"<<endl << cnt << endl << endl;

    }
    return 0;
}