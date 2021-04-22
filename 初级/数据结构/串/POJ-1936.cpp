/*
	Author:     ztqakita
	Date:       2021-4-22
	Code:       POJ 1936
	Problem:    All in All
    Category:   Easy, 串
	URL:        http://poj.org/problem?id=1936
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
    string ss, s;
    while(cin >> ss >> s){
        int i = 0, j = 0;
        while(i < s.size()){
            if(s[i] == ss[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        if(j != ss.size()){
            cout << "No" << endl;
        }
        else   
            cout << "Yes" << endl;
        }
    return 0;
}