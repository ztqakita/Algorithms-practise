/*
	Author:     ztqakita
	Date:       2021-2-27
	Code:       POJ 3295
	Problem:    Tautology
    Category:   Easy, 构造
	URL:        http://poj.org/problem?id=3295
    WA: 1 time
*/

/*
    此题并非自己做出来的！
	题意分析：
    输入由p、q、r、s、t、K、A、N、C、E共10个字母组成的逻辑表达式WFF
      其中 
	    p、q、r、s、t的值为1（true）或0（false），即逻辑变量.

        K、A、N、C、E为逻辑运算符，含义如下：
         K --> and:  w && x
         A --> or:  w || x
         N --> not :  !w
         C --> implies :  (!w) || x
         E --> equals :  w == x

      问WFF是否为【永真式】 (大前提：【输入格式保证是合法的】)

    解题思路：
    前缀表达式的处理方式：从后向前处理表达式，遇到元素就压入栈中，遇到运算符就取出栈中元素进行运算，并将结果压回栈中。
    所谓的永真式, 就是不管WFF中的逻辑变量取任何值, 整个逻辑表达式的值始终为真.
	  题目给出的逻辑变量共5个, 根据排列组合共 2^5 = 32 种组合变化
	  那么只要计算WFF在这32种组合中的所有结果, 若均为真, 则WFF是永真式.

	  那么问题剩下如何求解WFF.

	    以样例输入的WFF表达式为例：ApNq
	      其真正的含义是： A(p, N(q))

	    更为复杂的情况是：EKpNAqrCsNt
	      其含义是：E(K(p, N(A(q, r)), C(s, N(t)))

	  对于要求解这类嵌套表达式的值, 最好的数据结构是栈：
	    从最内层开始计算, 逐层向外推演

	  在本题中, 由于只存在一目和二目运算符, 因此内层的运算总是在表达式末端,
	  为此推演WFF表达式的算法是：
	    从WFF表达式最后一个字符向前迭代：
		① 遇到逻辑变量，则把该逻辑变量的当前值(0或1)直接压栈
		② 遇到逻辑算符, 则根据是一目算符或二目算符，从栈顶取出对应两个逻辑变量值计算后, 把结果值压栈

	  由于题目已经给出了一个大前提：【输入格式保证是合法的】
	  因此整个过程无需考虑WFF表达式是否存在异常的情况，
	  所以根据上述算法运算到最后，栈内必定只剩一下一个元素，该元素就是整个表达式的值.

	  ================================================================================
	  另外有个小技巧：
	    由于存在5个逻辑变量, 常规枚举会产生5层循环嵌套.
		考虑到这5个变量只有0/1值, 可以用一个bit代表一个变量, 将5个变量编码成一个byte, 
		那就可以优化成一层循环（枚举[0, 31]），通过掩码取某个逻辑变量的值即可
    
*/
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

#define ECODE 0x1f

stack<char> s;

char toValue(char ch, char code){
    char value;
    switch(ch){
        case 'p': { value = ((0x1 & code) == 0 ? 0 : 1); break; }
        case 'q': { value = ((0x2 & code) == 0 ? 0 : 1); break; }
        case 'r': { value = ((0x4 & code) == 0 ? 0 : 1); break; }
        case 's': { value = ((0x8 & code) == 0 ? 0 : 1); break; }
        case 't': { value = ((0x16 & code) == 0 ? 0 : 1); break; }
        default: { value = ch; break;}
    }
    return value;
}

int main(){
    char wff[110];
    char w, x;
    bool isT;
    while(cin >> wff && wff[0] != '0'){
        const int len = strlen(wff);
        for(char code = 0; code <= ECODE; code++){
            isT = false;
            for(int i = len-1; i >= 0; i--){
                char value = toValue(wff[i], code);

                if(value <= 1)
                    s.push(value);

                else{
                    switch (value)
                    {
                    case 'K':
                        w = toValue(s.top(), code);
                        s.pop();
                        x = toValue(s.top(), code);
                        s.pop();
                        s.push(w && x);
                        break;
                    
                    case 'A':
                        w = toValue(s.top(), code);
                        s.pop();
                        x = toValue(s.top(), code);
                        s.pop();
                        s.push(w || x);
                        break;

                    case 'N':
                        w = toValue(s.top(), code);
                        s.pop();
                        s.push(!w);
                        break;

                    case 'C':
                        w = toValue(s.top(), code);
                        s.pop();
                        x = toValue(s.top(), code);
                        s.pop();
                        s.push((!w) || x);
                        break;

                    case 'E':
                        w = toValue(s.top(), code);
                        s.pop();
                        x = toValue(s.top(), code);
                        s.pop();
                        s.push(w == x);
                        break;
                    default:
                        break;
                    }

                }
            }

            if(s.size()==1 && s.top()==1){
                isT = true;
                s.pop();
            }
            else{
                s.pop();
                break;
            }
        }
        if(isT == false)
            cout << "not" << endl;
        else 
            cout << "tautology" << endl;
    }
    return 0;
}