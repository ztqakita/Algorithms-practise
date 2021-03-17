/*
	Author:     ztqakita
	Date:       2021-3-9
	Code:       POJ 1008
	Problem:    Maya Calendar
    Category:   Easy, 初级模拟
	URL:        http://poj.org/problem?id=1008
*/

/*
    纯模拟，没什么好说的
    玛雅历年份转换
    好像OJ平台的编译器对于map容器的构造方式并不支持，所以以后机考还是少用map吧。
*/

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main(){
    map<string, int> str2mon{{"pop", 1}, {"no", 2}, {"zip", 3}, {"zotz",4},{"tzec",5}, {"xul",6}, {"yoxkin",7}, 
{"mol",8}, {"chen",9}, {"yax",10}, {"zac",11}, {"ceh",12}, {"mac",13}, {"kankin",14}, {"muan",15}, {"pax",16}, {"koyab",17}, {"cumhu",18}, {"uayet", 19}};

    string Name[20] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};

    int n;
    int year, day, mon;
    int sum;
    string month;
    cin >> n;
    while(n--){
        scanf("%d. ", &day);
        cin >> month >> year;
        map<string, int>::iterator iter;
        iter = str2mon.find(month);
        sum = year * 365 + (iter->second-1)*20 + day + 1;

        int Tyear = sum / 260;
        int TdayName = sum%20;
        int TdayID = sum%13;

        cout << TdayID << " " << Name[TdayName-1] << " " << Tyear << endl;
    }
    return 0;
}

