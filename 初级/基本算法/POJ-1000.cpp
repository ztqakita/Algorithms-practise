#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    long long l , r, temp, max, cnt=0, min, man;
    while(scanf("%lld %lld", &l, &r)!=EOF){
        max = 0;
        if(l < r){
            min = l;
            man = r;
        }
        else
        {
            min = r;
            man = l;
        }
        for(long long i = min; i<=man; i++){
            temp = i;
            cnt = 1;
            while(temp != 1){
                if(temp % 2 == 0){
                    temp /= 2;
                }
                else{
                    temp = 3*temp+1;
                }
                cnt++;
            }
            if(cnt > max){
                max = cnt;
            }
        }
        printf("%lld %lld %lld\n", l, r, max);
    }
    return 0;
}