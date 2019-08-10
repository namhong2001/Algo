#include <stdio.h>
#include <algorithm>
using namespace std;
 
int T;
 
struct P{
    int x, y;
    int s(){ return this->x + this->y; }
} B[4];
 
struct L{
    L(){}
    L(const P &a, const P &b): a(a), b(b){}
    P a, b;
} A;
 
int ccw(const P &a, const P &b, const P &c)
{
    int k = (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
    if (k > 0) return 1;
    if (k) return -1;
    return 0;
}
 
int insc(L p, L q)
{
    if (!ccw(p.a, p.b, q.a) && !ccw(p.a, p.b, q.b)){
        if (p.a.s() > p.b.s()) swap(p.a, p.b);
        if (q.a.s() > q.b.s()) swap(q.a, q.b);
        int a = p.a.s(), b = p.b.s(), c = q.a.s(), d = q.b.s();
        if (b < c || d < a) return 0;
        if (b == c || a == d) return 1;
        return -1;
    }
    if (ccw(p.a, p.b, q.a) == ccw(p.a, p.b, q.b) || ccw(q.a, q.b, p.a) == ccw(q.a, q.b, p.b)) return 0;
    return 1;
}
 
int main()
{
    int i;
    for (scanf("%d", &T);T--;){
        scanf("%d%d%d%d", &B[0].x, &B[0].y, &B[2].x, &B[2].y);
        scanf("%d%d%d%d", &A.a.x, &A.a.y, &A.b.x, &A.b.y);
        B[1].x = B[2].x, B[1].y = B[0].y;
        B[3].x = B[0].x, B[3].y = B[2].y;
        int ans = 0;
        for (i=0; i<4; i++){
            int v = insc(A, L(B[i], B[(i+1)%4]));
            if (v == -1) break;
            ans += v;
            v = insc(A, L(B[i], B[i]));
            if (v) ans--;
        }
        printf("%d\n", i<4?4:ans);
    }
} 
