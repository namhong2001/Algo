#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
const int N=310;
int n,m,K,c[N][N],r[N][N],A[N];
void solve(){
	scanf("%d%d%d",&n,&m,&K); 
	int ans=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) scanf("%d",&c[i][j]);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			int mi=c[i][j],ma=c[i][j],k;
			for (k=j+1;k<=m;k++){
				mi=min(mi,c[i][k]),ma=max(ma,c[i][k]);
				if (ma-mi>K) break;
			}
			r[i][j]=k;
		}
	for (int kk=1;kk<=m;kk++){
		for (int i=1;i<=n;i++) A[i]=r[i][kk]-kk;
		for (int i=1;i<=n;i++){
			int now=A[i];
			for (int j=i;j<=n;j++){
				now=min(now,A[j]); ans=max(ans,now*(j-i+1));
			}
		}
	}
	printf("%d\n",ans);
}
int main(){
	int t; scanf("%d",&t);
	for (int i=1;i<=t;i++){
		printf("Case #%d: ",i); solve();
	}
}