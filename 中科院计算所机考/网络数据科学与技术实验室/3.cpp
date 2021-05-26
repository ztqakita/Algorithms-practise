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

int matrix[500][500] = {0};
int degree[500] = {0};
int year[500] = {0};
bool visit[500] = {0};
int ans[500] = {0};
int cnt = 0;

int main(){
    int N;
    int min;
    ifstream infile("input3.txt"); 
    infile >> N;
    int p1, y1, p2, y2;
    for(int i = 1; i <= N; i++){
        infile >> p1 >> y1 >> p2 >> y2;
        matrix[p1][p2] = 1;
        degree[p1] ++;
        year[p1] = y1;
        year[p2] = y2;
    }
    bool flag = true;
    while(flag){
        vector<int> list;
        flag = false;
        for(int i = 1; i <= N; i++){
            if(degree[i] == 0 && !visit[i]){
                min = i;
                list.emplace_back(i);
            }
        }
        
        for(auto& it : list){
            if(year[it] < year[min])
                min = it;
        }
        list.clear();
        ans[cnt++] = min;
        visit[min] = true;
        for(int next = 1; next <= N; next++){
            if(matrix[next][min]){
                degree[next] --;
            }
        }
        for(int i = 1; i <= N; i++){
            if(visit[i] == false){
                flag = true;
                break;
            }
        }
    }

    for(int i = 0; i < cnt; i++){
        cout << ans[i] << " ";
    }
}