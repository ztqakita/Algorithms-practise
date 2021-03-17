/*
	Author:     ztqakita
	Date:       2021-3-12
	Code:       POJ 3087
	Problem:    Shuffle'm Up
    Category:   Easy, 初级模拟
	URL:        http://poj.org/problem?id=3087
*/

/*
    水题
    可以优化的地方：
    在判重时，可以使用map等容器，map使用红黑树数据结构，搜索更快。
*/

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

bool compare(char *s12, char *target, int C){
    for(int i = 0; i < 2*C; i++){
        if(s12[i] != target[i])
            return false;
    }
    return true;
}

int main(){
    int N, C;
    char S1[1001], S2[1001];
    char S12[2002], target[2002];
    char memory[1001][2002];
    cin >> N;
    for(int number = 1; number <= N; number++){
        cin >> C;
        memset(S1, '\0', sizeof(S1));
        memset(S2, '\0', sizeof(S2));
        memset(S12, '\0', sizeof(S12));
        memset(target, '\0', sizeof(target));
        memset(memory, '\0', sizeof(memory));
        for(int i = 0; i < C;i++)
            cin >> S1[i];
        for(int i = 0; i < C;i++)
            cin >> S2[i];
        for(int i = 0; i < 2*C;i++)
            cin >> target[i];
        int count = 0;
        int memNum = 0;
        int flag = 1;
        while(!compare(S12, target, C)){
            count ++;
            for(int i = 0; i < 2*C; i+=2){
                S12[i] = S2[i/2];
                S12[i+1] = S1[i/2];
            }
            if(compare(S12, target, C)){
                cout << number << " " << count << endl;
                break;
            }
            for(int i = 0; i < memNum; i++){
                if(compare(S12, memory[i], C)){
                    cout << number << " " << -1 << endl;
                    flag = 0;
                    break;
                }
            }

            if(!flag){
                break;
            }
            else{
                for(int i = 0; i < C; i++)
                    S1[i] = S12[i];
                for(int i = 0; i < C; i++)
                    S2[i] = S12[i+C];
                strcpy(memory[++memNum], S12);
            }
        }
    }
    return 0;
}