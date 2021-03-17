/*
	Author:     ztqakita
	Date:       2021-3-10
	Code:       POJ 2632
	Problem:    Crashing Robots
    Category:   Easy, 初级模拟
	URL:        http://poj.org/problem?id=2632
*/

/*
    很烦的地图行走模拟，没有难点，就是考你细心程度，这题花这么长时间实在不应该！
*/

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main(){
    int K;
    int X[101], Y[101];
    int robot[101], repeat[101];
    char D[101], action[101];
    cin >> K;
    while(K--){
        int A, B, N, M; 
        cin >> A >> B >> N >> M;
        for(int i = 1; i <= N; i++){
            cin >> X[i] >> Y[i] >> D[i];
        }
        for(int i = 0; i < M; i++){
            cin >> robot[i] >> action[i] >> repeat[i];
        }
        for(int i = 0; i < M; i++){
            int flag = 1;
            for(int r = 0; r < repeat[i]; r++){
                switch(action[i]){
                    case 'F':
                        if(D[robot[i]]=='N')
                            Y[robot[i]] ++;
                        else if(D[robot[i]]=='E')
                            X[robot[i]] ++;
                        else if(D[robot[i]]=='S')
                            Y[robot[i]] --;
                        else if(D[robot[i]]=='W')
                            X[robot[i]] --;
                        break;
                    case 'L':
                        if(D[robot[i]]=='N')
                            D[robot[i]] = 'W';
                        else if(D[robot[i]]=='E')
                            D[robot[i]] = 'N';
                        else if(D[robot[i]]=='S')
                            D[robot[i]] = 'E';
                        else if(D[robot[i]]=='W')
                            D[robot[i]] = 'S';
                        break;
                    case 'R':
                        if(D[robot[i]]=='N')
                            D[robot[i]] = 'E';
                        else if(D[robot[i]]=='E')
                            D[robot[i]] = 'S';
                        else if(D[robot[i]]=='S')
                            D[robot[i]] = 'W';
                        else if(D[robot[i]]=='W')
                            D[robot[i]] = 'N';
                        break;
                }

                for(int j = 1; j <= N && flag; j++){
                    if(X[robot[i]]==X[j] && Y[robot[i]]==Y[j] && robot[i] != j){
                        cout << "Robot " << robot[i] << " crashes into robot " << j << endl;
                        flag = 0;
                    }
                }

                if(flag && (X[robot[i]] <= 0 || X[robot[i]] > A || Y[robot[i]] <= 0 || Y[robot[i]] > B)){
                    cout << "Robot " << robot[i] << " crashes into the wall" << endl;
                    flag = 0;
                }

                if(!flag)
                    break;
                
            }
            if(flag && i==M-1)
                cout << "OK" <<endl;
            else if(flag == 0)
                break;
        }
    }
    return 0;
}