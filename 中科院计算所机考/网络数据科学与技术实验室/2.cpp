#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <stack>
using namespace std;

int main(){
    stack<string> stk;
    string type, name;
    int N;
    bool bug = false;
    ifstream infile("input2.txt"); 
    infile >> N;
    for(int i = 0; i < N; i++){
        infile >> type >> name;
        if(type == "INVOKE"){
            if(i == 0 && name != "main"){
                bug = true;
                break;
            }
            stk.push(name);
        }
        else if(type == "READ"){
            int j;
            for(j = 0; j < name.size(); j++){
                if(name[j] == '#')
                    break;
            }
            string func = name.substr(0, j);
            if(func != stk.top()){
                bug = true;
                break;
            } 
        }
        else{
            if(name != stk.top()){
                bug = true;
                break;
            }
            else{
                stk.pop();
            }
        }

        if(stk.size() == 0 && i < N-1){
            bug = true;
            break;
        }
    }
    if(bug)
        cout << "YES";
    else
        cout << "NO";
}