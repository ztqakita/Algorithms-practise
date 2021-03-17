/*
	Author:     ztqakita
	Date:       2021-3-11
	Code:       POJ 2255
	Problem:    Tree Recovery
    Category:   Easy, 图遍历
	URL:        http://poj.org/problem?id=2255
*/

/*
    树的问题，如何抽象快速解决，而不是靠模拟来解决问题是需要锻炼的
    题意分析：
	  给出一棵二叉树的前序遍历与中序遍历，求后序遍历.
	  其中二叉树由不重复的大写字母组成，每个节点一个字母.

	解题思路：
	 ① 前序遍历的第一个字母必是 根
	 ② 在中序遍历的字母串中找出 根字母，那么根字母左右两边的字符串就分别是它的左、右子树
	 ③ 由于树的最大深度只有26，因此可以不考虑堆栈溢出，利用[递归]结合①②复原二叉树
	 ④ 对复原的二叉树使用DFS做后序遍历即可

	 注：
	  对二叉树的 前序遍历、中序遍历、后序遍历 均可以使用DFS来做，
	  均是自上而下、自左至右遍历，区别在于打印节点的时机不同：
	  [前序遍历] 从父节点进入时打印当前节点
	  [中序遍历] 从左子树返回时打印当前节点
	  [后序遍历] 从右子树返回时打印当前节点
*/

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

string f(string pre, string in){
    int len = in.length();
    if(len == 1)
        return in;
    else if(len == 0)
        return "";
    else{
        int loc = in.find(pre[0]);
        return f(pre.substr(1, loc), in.substr(0, loc)) + f(pre.substr(loc+1), in.substr(loc+1)) + pre[0];
    }
}

int main(){
    string preorder, inorder, postorder;
    while(cin >> preorder >> inorder){
        string s = f(preorder, inorder);
        cout << s << endl;
    }
    return 0;
}