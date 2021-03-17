/*
	Author:     ztqakita
	Date:       2021-1-14
	Code:       POJ 1753
	Problem:    Flip Game
    Category:   Easy, 搜索；DFS
	URL:        http://poj.org/problem?id=1753
*/

/*          此题并非自己做出来的！
    【题意分析】
	 有一4x4棋盘，上面有16枚双面棋子（一面为黑，一面为白），
	 当翻动一只棋子时，该棋子上下左右相邻的棋子也会同时翻面。
	 以b代表黑面，w代表白面，给出一个棋盘状态，
	 问从该棋盘状态开始，使棋盘变成全黑或全白，至少需要翻转多少步

    【解题思路】
     本题最经典的解决思路就是搜索(暴力枚举)，由当前棋盘开始向下展开搜索树，
     对于每个格子，它要么反转0次，要么反转1次(当然，它的邻格子也跟着反转)，
     因为它反转偶数次和反转0次的效果是一样的，同理反转奇数次的效果和反转1次的效果是一样的。
     由于有16个棋子，所以该搜索树是一棵16叉树，通过DFS来寻找结点为全黑或全白的棋盘，
     通过翻棋次数来枚举，这个相当于作为树高的限制条件。
*/

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int chess[6][6];    //棋盘
int r[5] = {-1, 0, 1, 0, 0};    //上下左右四个方位
int c[5] = { 0,-1, 0, 1, 0};
int step;
bool flag;

bool judge(){
    for(int i = 1; i <= 4; i++)
        for(int j = 1; j <= 4; j++){
            if(chess[i][j] != chess[1][1])
                return false;
        }
    return true;
}

void flip(int i, int j){
    for(int k = 0; k < 5; k++)
        chess[i+r[k]][j+c[k]] = !chess[i+r[k]][j+c[k]];
}

void dfs(int i, int j, int depth){  //子集树
    if(step == depth){
        flag = judge();
        return;
    }

    if(flag || i == 5)
        return;

    flip(i, j);    
    if(j < 4)
        dfs(i, j+1, depth+1);
    else
        dfs(i+1, 1, depth+1);

    flip(i, j);  //回溯
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
            if(ch == 'b')
                chess[i][j] = 1;
            else
                chess[i][j] = 0;
        }

    for(step = 0; step <= 16; step++){
        dfs(1, 1, 0);
        if(flag)
            break;
    }

    if(flag)
        cout << step << endl;
    else
    {
        cout << "Impossible" << endl;
    }
    
    return 0;
}
