/*
	Author:     ztqakita
	Date:       2021-1-15
	Code:       POJ 1328
	Problem:    Radar Installation
    Category:   Easy, 贪心
	URL:        http://poj.org/problem?id=1328
    Runtime Error: 3 times
    WA: 1 time
*/

/*              此题并非自己做出来的！
	题意分析：
	  给定一个直角坐标系，定义x轴为海岸线，海岸线上方是海，下方是陆地。
	  在海域零星分布一些海岛, 需要要在海岸线上安装若干个雷达覆盖这些海岛,
	  每个雷达的覆盖半径都是相同且固定的。

	  现在给定所有海岛的坐标(x,y), 以及雷达的覆盖半径d，
	  问可以覆盖所有海岛的最小雷达数.

    解题思路：
      首先可以明确的是：只要存在任意一个海岛位置超出雷达最大覆盖半径（即y>d），则无解.

	  在所有海岛的 y<=d 的前提下去思考此问题，
	  那么此问题的切入点是需要知道【一个雷达要覆盖一个海岛，其可以安装范围是多少】

	  以海岛坐标(x,y)为圆心，用雷达覆盖半径d画圆，根据前提条件可知，
	  这个圆与x轴必定存在最少1个(y=d)、最多2个交点(y<d).

	  可以认为1个交点是2个交点重合的特殊情况，那么这2个交点在x轴上构成的线性区间，
	  可以看作海岛的被覆盖范围在x轴上的投影 (由此就可以把二维的几何问题转化成一维几何问题)

	  按照所有海岛的x轴坐标，从小到大依次计算每个海岛在x轴上的投影区间（投影可能存在重叠），
	  同时把每个雷达抽象成1个点，那么此问题就转化成：

	  【已知x轴上若干个区间（可能存在交集），现在要往这些区间内放若干个点，
	  问怎样放置这些点，使得每个区间内至少存在一个点，且所放置的点的总量尽可能最少】
	
	  
	  可使用贪心算法求解：
	    根据每个区间的左端点坐标对所有区间从左到右排序:
		① 在左起第一个区间A 的右端点 A.R 放置一个点，总放置点数 P+1 
		② 若下一个区间B 的左端点 B.L > A.R, 
		    说明 区间A 与 区间B 无交集，此时在区间B 的右端点 B.R 放置一个点，总放置点数 P+1 

		   否则说明 区间A 与 区间B 相交, 此时进一步判断，若 B.R < A.R，
			说明 区间B 在 区间A 的内部，此时把原本放置在 A.R 的点移动到 B.R（确保区间B有一个点），总放置点数不变

		③ 重复这个过程直到所有区间被遍历完成

*/

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define INF 0x3f3f3f3f

typedef struct Interval{
    double left;
    double right;
}Interval;

bool compare(Interval a, Interval b){   //根据island坐标的横坐标由小到大排序
    return a.left <= b.left;
}

int main(){
    int n, d, cnt=1, flag = 0;
    int x, y;
    int points;
    cin >> n >> d;
    while(n != 0 && d != 0){
        flag = 0;                                   //没有初始化导致你总是WA
        const double R2 = d * d;
        Interval* itval = new Interval[n+2];
        for(int i = 0; i < n; i++){
            cin >> x >> y;

            if(y > d){   //超出范围区
                flag = 1;
            }

            itval[i].left = x - sqrt(R2 - y*y);     //得到每一个island投影到x轴上的区域
            itval[i].right = x + sqrt(R2 - y*y);
        }
        
        if(!flag){
            sort(itval, itval+n, compare);
            points = 1;
            double right = itval[0].right;
            for(int i = 1; i < n; i++){
                if(itval[i].left > right){
                    points++;
                    right = itval[i].right;
                }
                else if(itval[i].right < right){
                    right = itval[i].right;
                }
            }
        }
        else
        {
            points = -1;
        }
        
        cout << "Case " << cnt << ": " << points << endl;
        cnt++;
        delete[] itval;
        cin >> n >> d;
    }
}