#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;


template<typename F>
struct FixPoint : F{
  FixPoint(F&& f):F(forward<F>(f)){}
  template<typename... Args>
  decltype(auto) operator()(Args&&... args) const{
    return F::operator()(*this,forward<Args>(args)...);
  }  
};
template<typename F>
inline decltype(auto) MFP(F&& f){
  return FixPoint<F>{forward<F>(f)};
}

//INSERT ABOVE HERE
void solve(){
  Int n,h,w,y,x;
  cin>>n>>h>>w>>y>>x;
  string s;
  cin>>s;

  using P = pair<Int, Int>;
  using T = tuple<Int, Int, Int>;
  set<P> sp;
  map<T, T> nxt;

  Int dy[]={-1,1,0,0};
  Int dx[]={0,0,1,-1};

  sp.emplace(y,x);  
  for(Int i=0;i<n;i++){    
    Int d=-1;
    if(s[i]=='N') d=0;
    if(s[i]=='S') d=1;
    if(s[i]=='E') d=2;
    if(s[i]=='W') d=3;
    assert(~d);
    
    tie(y,x,ignore)=
      MFP([&](auto dfs,Int cy,Int cx,Int cd)->T{
            assert(sp.count(P(cy,cx)));           
            {
              Int ny=cy+dy[cd];
              Int nx=cx+dx[cd];
              if(!sp.count(P(ny,nx)))
                return nxt[T(cy,cx,cd)]=T(ny,nx,cd);              
            }            
            if(nxt.count(T(cy,cx,cd))){
              Int ny,nx,nd;
              tie(ny,nx,nd)=nxt[T(cy,cx,cd)];              
              return nxt[T(cy,cx,cd)]=dfs(ny,nx,nd);              
            }            
            Int ny=cy+dy[cd];
            Int nx=cx+dx[cd];      
            return nxt[T(cy,cx,cd)]=dfs(ny,nx,cd);            
          })(y,x,d);
    
    sp.emplace(y,x);
  }
  
  cout<<y<<" "<<x<<"\n";
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
