/*
	Author:     ztqakita
	Date:       2021-1-14
	Code:       POJ 2965
	Problem:    The Pilots Brothers' refrigerator
    Category:   Easy, 搜索；DFS
	URL:        http://poj.org/problem?id=2965
*/

/*
    【题意分析】
	 有一冰箱，上面4x4共16个开关（"-"状态表示open，"+"状态表close）， 
	  当改变一个开关状态时，该开关所在行、列的全部开关状态也会同时改变。 

	  给出一个开关状态，问从该状态开始，使得所有开关打开（全"-"），
	  至少需要操作多少步，并把操作过程打印出来（打印所操作开关的行列坐标，坐标从1开始）

    【解题思路】
     本题的解决思路与POJ-1753一模一样，只不过需要输出翻转的顺序结果，
	 记录结果的方法就是课上讲过的常规套路。
	 此题除了用二维数组来存储以外，还可以使用状态压缩：16bits来表示每一个点的状态。
*/

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int chess[6][6];    //棋盘
int bestx[6][6]={0};	//记录结果
int x[6][6]={0};		//当前最优结果
int step;
bool flag;

bool judge(){
    for(int i = 1; i <= 4; i++)
        for(int j = 1; j <= 4; j++){
            if(chess[i][j] != 0)
                return false;
        }
    return true;
}

void flip(int i, int j){
	for(int l = 1; l < 5; l++)
		chess[i][l] = !chess[i][l];
	for(int l = 1; l < 5; l++)
		chess[l][j] = !chess[l][j];
    chess[i][j] = !chess[i][j];
}

void dfs(int i, int j, int depth){  //子集树
    if(step == depth){
        flag = judge();
		if(flag){
			for(int k = 1; k < 5; k++)
				for(int m = 1; m < 5; m++){
					bestx[k][m] = x[k][m];
			}
		}
        return;
    }

    if(flag || i == 5)
        return;

    flip(i, j);
	x[i][j] = 1;
    if(j < 4)
        dfs(i, j+1, depth+1);
    else
        dfs(i+1, 1, depth+1);

    flip(i, j);  //回溯
	x[i][j] = 0;
    if(j < 4)
        dfs(i, j+1, depth); //此处为debug出错点，当出现回溯之后再往下寻找时，深度并没有增加！（并没有翻新的棋子）
    else
        dfs(i+1, 1, depth);
}

int main(){
    char ch;
    for(int i = 1; i < 5; i++)
        for(int j = 1; j < 5; j++)
        {
            cin >> ch;
            if(ch == '+')
                chess[i][j] = 1;
            else
                chess[i][j] = 0;
        }

    for(step = 0; step <= 16; step++){
        dfs(1, 1, 0);
        if(flag)
            break;
    }

    if(flag){
        cout << step << endl;
		for(int k = 1; k < 5; k++)
			for(int m = 1; m < 5; m++){
				if(bestx[k][m]){
					cout << k << " " << m << endl;
				}
		}
	}
    else
    {
        cout << "Impossible" << endl;
    }
    
    return 0;
}
