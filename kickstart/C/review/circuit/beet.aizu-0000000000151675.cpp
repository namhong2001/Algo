#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

template<typename T>
T largestrectangle(vector<T> &v){
  Int n=v.size();
  T res=0;
  using P = pair<Int, T>;
  stack<P> sp;
  sp.emplace(-1,T(0));
  for(Int i=0;i<n;i++){
    Int j=i;
    while(sp.top().second>v[i]){
      j=sp.top().first;
      chmax(res,(i-j)*sp.top().second);
      sp.pop();
    }
    if(sp.top().second<v[i]) sp.emplace(j,v[i]);
  }
  while(!sp.empty()){
    chmax(res,(n-sp.top().first)*sp.top().second);
    sp.pop();
  }
  return res;
}

struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;


template<typename T, typename F>
struct DisjointSparseTable{
  vector<vector<T> > dat;
  vector<Int> ht;
  const F f;
  
  DisjointSparseTable(F f):f(f){}
  
  void build(const vector<T> &v){
    Int n=v.size(),h=1;
    while((1<<h)<=n) h++;
    dat.assign(h,vector<T>(n));
    ht.assign((1<<h)+1,0);
    for(Int j=2;j<(1<<h)+1;j++) ht[j]=ht[j>>1]+1;
    
    for(Int j=0;j<n;j++) dat[0][j]=v[j];
    for(Int i=1;i<h;i++){
      Int s=1<<i;
      for(Int j=0;j<n;j+=s<<1){
        Int t=min(j+s,n);
        dat[i][t-1]=v[t-1];
        for(Int k=t-2;k>=j;k--) dat[i][k]=f(v[k],dat[i][k+1]);
        if(n<=t) break;
        dat[i][t]=v[t];
        Int r=min(t+s,n);
        for(Int k=t+1;k<r;k++) dat[i][k]=f(dat[i][k-1],v[k]);
      }
    }
  }

  T query(Int l,Int r){
    if(l>=--r) return dat[0][l];
    return f(dat[ht[l^r]][l],dat[ht[l^r]][r]);
  }
  
};

//INSERT ABOVE HERE
void solve(){  
  Int h,w,d;
  cin>>h>>w>>d;
  vector<vector<Int>> st(h,vector<Int>(w));
  for(Int i=0;i<h;i++)
    for(Int j=0;j<w;j++)
      cin>>st[i][j];
  
  using P = pair<Int, Int>;
  auto f=
    [](P a,P b)->P{
      return P(max(a.first,b.first),min(a.second,b.second));
    };
  vector<DisjointSparseTable<P, decltype(f)>> ds(h,f); 
  for(Int i=0;i<h;i++){
    vector<P> vp(w);
    for(Int j=0;j<w;j++) vp[j]=P(st[i][j],st[i][j]);
    ds[i].build(vp);  
  }
  
  Int ans=0;
  for(Int j=0;j<w;j++){
    vector<Int> v(h);
    for(Int i=0;i<h;i++){
      Int l=j,r=w;      
      while(l+1<r){
        Int m=(l+r)>>1;
        auto p=ds[i].query(j,m+1);
        if(p.first-p.second<=d) l=m;
        else r=m;        
      }
      v[i]=r-j;  
    }
    chmax(ans,largestrectangle(v));
  }  
  cout<<ans<<"\n";
}

signed main(){
  Int T;
  cin>>T;
  for(Int t=1;t<=T;t++){
    cout<<"Case #"<<t<<": ";
    solve();
  }
  cout<<flush;
  return 0;
}
