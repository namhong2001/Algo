#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<assert.h>
#include<set>
#include<cmath>
#include<queue>
#include<cstdlib>
#include<iostream>
#include<bitset>
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define rep(i,j,k) for(int i=(int)(j);i<=(int)(k);i++)
#define per(i,j,k) for(int i=(int)(j);i>=(int)(k);i--)
using namespace std;
typedef long long LL;
typedef double db;
const int N=305;
int n,m,S,cas;
int a[N][N];
int ma[N][N][N];
int mi[N][N][N];
void Main(){
	scanf("%d%d%d",&n,&m,&S);
	rep(i,1,n)rep(j,1,m)scanf("%d",&a[i][j]);
	rep(i,1,n){
		rep(j,1,m){
			ma[i][j][j]=mi[i][j][j]=a[i][j];
			rep(k,j+1,m){
				ma[i][j][k]=max(ma[i][j][k-1],a[i][k]);
				mi[i][j][k]=min(mi[i][j][k-1],a[i][k]);
			}
		}
	}
	int ans=0;
	rep(l,1,m)rep(r,l,m){
		int w=0;
		rep(i,1,n)if(ma[i][l][r]-mi[i][l][r]<=S){w++;ans=max(ans,w*(r-l+1));}
		else w=0;
	}
	printf("Case #%d: %d\n",++cas,ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)Main();
	return 0;
}





