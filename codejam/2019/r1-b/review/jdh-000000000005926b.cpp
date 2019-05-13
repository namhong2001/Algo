#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = pow(10,9)+7;
ll getPow(ll a,ll p){
  ll ret = 1,cp = a;
  while(p){
    if(p&1) ret = (ret*cp)%MOD;
    p >>= 1;
    cp = (cp*cp)%MOD;
  }
  return ret;
}
ll getK(ll i,ll k){
  if(i == 1) return k%MOD;
  ll ret = ((i*(getPow(i,k)-1)%MOD)*getPow(i-1,MOD-2))%MOD;
  return ret;
}
int main(){
  int T;
  cin >> T;
  for(int k = 1; k <= T; ++k){
    ll N,K,x1,y1,C,D,E1,E2,F;
    cin >> N >> K >> x1 >> y1 >> C >> D >> E1 >> E2 >> F;
    vector<ll> A(N);
    A[0] = (x1+y1)%F;
    ll CD = C+D,E = E1+E2;
    for(ll i = 1; i < N; ++i) A[i] = (CD*A[i-1]+E)%F;
    ll psum = 0,nb = 1,kval = N,ret = 0;
    for(ll i = N-1; i >= 0; --i){
      psum = (psum+nb*A[i])%MOD;
      ++nb;
      ret = (ret+psum*getK(kval,K))%MOD;
      --kval;
    }
    cout << "Case #" << k << ": " << ret << "\n";
  }
  return 0;
}
