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

int main(){
    string s[1000001];
    freopen("input.txt","r",stdin);
    int n;
    while(cin >> n && n){
        for(int i = 1; i <= n; i++){
            s[i] = to_string(i);
        }
        int max = 1;
        for(int i = 1; i <= n; i++){
            if(s[i] > s[max])
                max = i;
        }
        cout << max << endl;
    }

}