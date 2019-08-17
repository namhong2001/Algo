#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
typedef double DB;
DB PI=acos(-1.0);
DB Area(DB x1,DB y1,DB r1,DB x2,DB y2,DB r2)
{
    double d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    if(d>=r1+r2)
        return 0;
    else if(fabs(r1-r2)>=d)
    {
        if(r1>r2)
            return PI*r2*r2;
        else
            return PI*r1*r2;
    }
    else
    {
        //正弦定理求扇形圆心角
        double a1=2*acos((r1*r1+d*d-r2*r2)/2/r1/d);
        double a2=2*acos((r2*r2+d*d-r1*r1)/2/r2/d);
        //两个扇形面积和减去四边形的面积即为相交区域面积
        //四边形面积再转化为两个三角形的面积之和来计算
        double ans=r1*r1*a1/2+r2*r2*a2/2-r1*r1*sin(a1)/2-r2*r2*sin(a2)/2;
        return ans;
    }
}
int main()
{
    double x1,y1,r1,x2,y2,r2;
    while(cin>>x1>>y1>>r1>>x2>>y2>>r2)
    {
        printf("%.3lf\n",Area(x1,y1,r1,x2,y2,r2));
    }
    return 0;
}


