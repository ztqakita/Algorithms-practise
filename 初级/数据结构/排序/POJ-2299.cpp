/*
	Author:     ztqakita
	Date:       2021-4-22
	Code:       POJ 2299
	Problem:    Ultra-QuickSort
    Category:   Easy, 排序
	URL:        http://poj.org/problem?id=2299
*/

/*
    【问题描述】
    给出长度为n的序列，每次只能交换相邻的两个元素，问至少要交换几次才使得该序列为递增序列。

    【解题思路】
    由于数据量大，不能使用复杂度O(n^2)的算法，所以需要使用归并排序来计算逆序数。
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

__int64 cnt = 0;

void merge(int *a, int left, int mid, int right){
    int i = left, j = mid+1, k = 1;
    int* b = new int[right-left+2];
    while(i <= mid && j <= right){
        if(a[i] < a[j])
            b[k++] = a[i++];
        else{
            b[k++] = a[j++];
            cnt += mid-i+1;
        }
    }
    while(i <= mid){
        b[k++] = a[i++];
    }

    while(j <= right)  
        b[k++] = a[j++];

    int cnt = 1;
    for(int l = left; l <= right; l++)
        a[l] = b[cnt++];

    delete b;
}

void mergeSort(int *a, int left, int right){
    int mid = (left + right) / 2;
    if(left >= right)
        return;
    mergeSort(a, left, mid);
    mergeSort(a, mid+1, right);
    merge(a, left, mid, right);
}

int main(){
    int n;
    while(cin >> n && n){
        int* a=new int[n+1];
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        cnt = 0;
        mergeSort(a, 1, n);
        printf("%I64d\n",cnt);
        delete a;
    }
    return 0;
}