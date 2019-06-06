#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
struct atom{
	int l,r;
};
int operator < (atom k1,atom k2){
	return k1.l<k2.l;
}
const int N=510000;
set<atom> A[N],B[N];
int n,m,sx,sy,K;
char ch[N];
int getpre(set<atom>* S,int cur){
	set<atom>::iterator k=S->upper_bound((atom){cur,cur});
	if (k==S->begin()) return cur-1;
	k--; atom now=*k; return now.l-1;
}
int getne(set<atom>* S,int cur){
	set<atom>::iterator k=S->upper_bound((atom){cur,cur});
	if (k==S->begin()) return cur-1;
	k--; atom now=*k; return now.r+1;
}
void insert(set<atom>* S,int cur){
	int l=cur,r=cur;
	set<atom>::iterator k=S->lower_bound((atom){cur,cur});
	if (k!=S->end()){
		atom now=*k; if (now.l==cur+1) {r=now.r; S->erase(k);}
	}
	k=S->lower_bound((atom){cur,cur});
	if (k!=S->begin()){
		k--; atom now=*k; if (now.r==cur-1) {l=now.l; S->erase(k);}
	}
	S->insert((atom){l,r});
}
void insert(int x,int y){
	insert(&A[x],y); insert(&B[y],x);
}
void solve(){
	scanf("%d%d%d",&K,&n,&m); scanf("%d%d",&sx,&sy);
	for (int i=1;i<=n;i++) A[i].clear();
	for (int i=1;i<=m;i++) B[i].clear();
	insert(sx,sy);
	scanf("%s",ch+1);
	for (int i=1;i<=K;i++){
		if (ch[i]=='N'){
			sx=getpre(&B[sy],sx);
		} else if (ch[i]=='S'){
			sx=getne(&B[sy],sx);
		} else if (ch[i]=='E'){
			sy=getne(&A[sx],sy);
		} else sy=getpre(&A[sx],sy);
		insert(sx,sy);
	}
	printf("%d %d\n",sx,sy);
}
int main(){
	int t; scanf("%d",&t);
	for (int i=1;i<=t;i++){
		printf("Case #%d: ",i); solve();
	}
}