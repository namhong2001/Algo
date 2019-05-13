#include<bits/stdc++.h>
using namespace std;

void tmain()
{
  puts("210"); fflush(stdout);
  long long d210; scanf("%lld", &d210);
  puts("42"); fflush(stdout);
  long long d42; scanf("%lld", &d42);
  
  int r4 = (d210>>52)&127;
  int r5 = (d210>>42)&127;
  int r6 = (d210>>35)&127;
  
  d42 -= (r4<<10);
  d42 -= (r5<<8);
  d42 -= (r6<<7);
  
  int r1 = (d42>>42)&127;
  int r2 = (d42>>21)&127;
  int r3 = (d42>>14)&127;
  printf("%d %d %d %d %d %d\n", r1, r2, r3, r4, r5, r6); fflush(stdout);
  int t; scanf("%d", &t);
  if(t == -1) exit(1);
}
int main()
{
  int T; scanf("%d", &T); int W; scanf("%d", &W);
  while(T--) tmain();
}