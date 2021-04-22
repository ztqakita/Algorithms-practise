/*
	Author:     ztqakita
	Date:       2021-4-22
	Code:       POJ 1035
	Problem:    Spell checker
    Category:   Easy, 串
	URL:        http://poj.org/problem?id=1035
*/

/*
    注意：POJ 上不能用auto& : 这种循环写法
    当串长度不同的时候进行对比，有可能指针的位置移动不同步，所以需要分情况！
    
    【问题描述】
    输入一部字典，输入若干单词
    若某个单词能在字典中找到，则输出corret  
    若某个单词能通过 变换 或 删除 或 添加一个字符后，在字典中找得到，则输出这些单词，输出顺序根据 输入的那部字典的字典序
    若某个单词无论操作与否都无法在字典中找得到，则输出空

    【解决思路】
    没难度的字符串处理。 暴力吧！模拟吧！
    基本思路就是逐个比较 待查单词 与 字典单词 的长度，当且仅当两者长度之差的绝对值 <=1 时才进行检查操作。
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

int cnt[10];

int main(){
    string str;
    vector<string> dic;
    while(cin >> str && str != "#"){
        dic.push_back(str);
    }
    while(cin >> str && str != "#"){
        vector<string> find_dic;
        bool flag = false;
        for(int word = 0; word < dic.size(); word++){
            if(str.size() == dic[word].size()){
                if(str == dic[word]){    // equal
                    flag = true;
                    break;
                }
                else{   // change
                    int diff = 0;
                    bool ok = true;
                    for(int i = 0; i < str.size() && ok; i++){
                        if(str[i] != dic[word][i]){
                            diff ++;
                            if(diff > 1){
                                ok = false;
                            }
                        }
                    }
                    if(ok){
                        find_dic.push_back(dic[word]);
                    }
                }
            }
            else if(str.size()-1 == dic[word].size()){   // sub
                int diff = 0;
                bool ok = true;
                int i = 0, j = 0;
                while(i < str.size() && ok){
                    if(str[i] != dic[word][j]){
                        i++;
                        diff++;
                        if(diff > 1)
                            ok = false;
                    }
                    else{
                        i++;
                        j++;
                    }
                }
                if(ok){
                    find_dic.push_back(dic[word]);
                }
            }
            else if(str.size()+1 == dic[word].size()){
                int diff = 0;
                bool ok = true;
                int i = 0, j = 0;
                while(i < dic[word].size() && ok){
                    if(dic[word][i] != str[j]){
                        i++;
                        diff++;
                        if(diff > 1)
                            ok = false;
                    }
                    else{
                        i++;
                        j++;
                    }
                }
                if(ok){
                    find_dic.push_back(dic[word]);
                }
            }
        }
        if(flag){
            cout << str << " is correct" << endl;
        }
        else{
            if(find_dic.empty()){
                cout << str << ":" << endl;
            }
            else{
                cout << str << ": ";
                for(int i = 0; i < find_dic.size(); i++){
                    cout << find_dic[i] << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}