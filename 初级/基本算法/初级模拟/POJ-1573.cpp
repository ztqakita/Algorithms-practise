/*
	Author:     ztqakita
	Date:       2021-3-12
	Code:       POJ 1573
	Problem:    Robot Motion
    Category:   Easy, 初级模拟
	URL:        http://poj.org/problem?id=1573
*/

/*
    纯练手的题，不用复习
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
    int row, col, entry;
    int x, y, sum;
    char path[101][101];
    int count[101][101];
    cin >> row >> col >> entry;
    while(row != 0 && col != 0 && entry != 0){
        sum = 0;
        int once = 0;
        int loop = 0;
        for(int i = 1; i <= row; i++)
            for(int j = 1; j <= col; j++){
                cin >> path[i][j];
                count[i][j] = 0;
            }
        x = 1;
        y = entry;
        while(x > 0 && x <= row && y > 0 && y <= col && count[x][y] < 2){
            count[x][y] += 1;
            switch (path[x][y])
            {
            case 'N':
                x--;
                break;
            case 'S':
                x++;
                break;
            case 'E':
                y++;
                break;
            case 'W':
                y--;
                break;
            default:
                break;
            }
            // cout << x << " " << y << endl;
            if(x <= 0 || x > row || y <= 0 || y > col){
                for(int i = 1; i <= row; i++)
                    for(int j = 1; j <= col; j++){
                        if(count[i][j] != 0)
                            sum ++;
                    }
                cout << sum << " step(s) to exit" << endl;
                break;
            }

            else if(count[x][y] >= 2){
                for(int i = 1; i <= row; i++)
                    for(int j = 1; j <= col; j++){
                        if(count[i][j] >= 2)
                            loop ++;
                        else if(count[i][j] == 1)
                            once++;
                    }
                cout << once << " step(s) before a loop of " << loop << " step(s)" << endl;
                break;
            }
        }

        cin >> row >> col >> entry;
    }
    return 0;
}