#include<bits/stdc++.h>
using namespace std;

const int MAXN = 131072;


int N, K;
int C[MAXN], D[MAXN];

int idx[2*MAXN];
int getv(int a, int b)
{
  int ans = 0;
  a += MAXN; b += MAXN;
  while(a<=b)
  {
    if(a%2==1) ans = max(ans, idx[a++]);
    if(b%2==0) ans = max(ans, idx[b--]);
    a /= 2; b /= 2;
  }
  return ans;
}
void setv(int a, int v)
{
  idx[a+=MAXN] = v;
  while((a=a/2))
    idx[a] = max(idx[2*a], idx[2*a+1]);
}

pair<int, int> findGE(int idx, int v)
{
  pair<int, int> ans;
  {
    int lo = -1; // must answer 
    int hi = idx+1; // must not
    while(lo+1!=hi)
    {
      int mi = (lo+hi)/2;
      if(getv(mi, idx) >= v) lo = mi;
      else hi = mi;
    }
    ans.first = lo;
  }
  {
    int lo = idx-1; // must not 
    int hi = N; // must answer
    while(lo+1!=hi)
    {
      int mi = (lo+hi)/2;
      if(getv(idx, mi) >= v) hi = mi;
      else lo = mi;
    }
    ans.second = hi;
  }
  return ans;
}
pair<int, int> findGT(int idx, int v)
{
  int ans1 = idx-1, ans2=idx;
  while(ans1>=0 && C[ans1]<v) --ans1;
  while(ans2<N && C[ans2]<=v) ++ans2;
  return make_pair(ans1, ans2);
}
long long tmain()
{
  scanf("%d%d", &N, &K);
  for(int i=0; i<N; ++i) scanf("%d", C+i);
  for(int i=0; i<N; ++i) scanf("%d", D+i);
  memset(idx, 0, sizeof idx);
  for(int i=0; i<N; ++i) setv(i, D[i]);
  long long ans = 0;
  for(int i=0; i<N; ++i)
  {
    if(C[i] + K < D[i]) continue;
    pair<int, int> idx = findGE(i, C[i]-K);
    pair<int, int> idx2 = findGE(i, C[i]+K+1);
    pair<int, int> idx3 = findGT(i, C[i]);
    /*cout << i <<endl;
    cout << idx.first << " " << idx.second << endl;
    cout << idx2.first << " " << idx2.second << endl;
    cout << idx3.first << " " << idx3.second << endl;
    cout << "==" <<endl;*/
    int a = max(idx3.first, idx2.first);
    int b = max(idx3.first, idx.first);
    int c = min(idx3.second, idx.second);
    int d = min(idx3.second, idx2.second);
    //cout << i << " " << a << " " << b << " " << c << " " << d << endl;
    ans += 1LL*(i-a)*(d-i);
    if(D[i] < C[i]-K)
      ans -= 1LL*(i-b)*(c-i);
  }
  return ans;
}
int main()
{
  int T; scanf("%d", &T);
  for(int i=1; i<=T; ++i)
  {
    printf("Case #%d: %lld\n", i, tmain());
  }
}