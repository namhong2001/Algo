#include<bits/stdc++.h>
using namespace std;
int N, Q;
int xc[101010];
int yc[101010];
int cm(int* a)
{
  int maxi = -1;
  int maxv = -10101001;
  int cnt = 0;
  for(int i=0; i<=Q; ++i)
  {
    cnt += a[i];
    if(maxv<cnt)
    {
      maxv = cnt;
      maxi = i;
    }
  }
  return maxi;
}
void tmain()
{
  memset(xc, 0, sizeof xc);
  memset(yc, 0, sizeof yc);
  scanf("%d%d", &N, &Q);
  for(int i=0; i<N; ++i)
  {
    int x, y; char c;
    scanf("%d%d %c", &x, &y, &c);
    if(c=='N') yc[y+1]++;
    else if(c=='S') yc[y]--;
    else if(c=='E') xc[x+1]++;
    else if(c=='W') xc[x]--;
  }
  printf("%d %d", cm(xc), cm(yc));
}
int main()
{
  int T; scanf("%d", &T);
  for(int tc=1; tc<=T; ++tc)
  {
    printf("Case #%d: ", tc);
    tmain();
    puts("");
  }
}