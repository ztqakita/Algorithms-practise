#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
using namespace std;

int main(){
    string a[200], b[200];

    int i = 0, j = 0, len_a, len_b;
    ifstream infile("input1.txt"); 
    do
    {
        infile >> a[i];
        i++;
    } while(infile.get() != '\n');
    len_a = i;
    do
    {
        infile >> b[j];
        j++;
    } while(infile.get() != '\n');
    len_b = j;
    i = j = 0;
    sort(a, a+len_a);
    sort(b, b+len_b);
    while(i < len_a && j < len_b){
        if(a[i] == b[j]){
            cout << a[i] << " ";
            i++;
            j++;
        }
        else{
            if(a[i] < b[j])
                i++;
            else   
                j++;
        }
    }
}