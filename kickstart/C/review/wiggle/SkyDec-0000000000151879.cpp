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
const int N=51000;
int cas=0;
int t;
map<int,int> l[N],r[N],u[N],d[N];
map<int,bool> hav[N];
int n,m,sx,sy,k;
bool fd(int x,int y){
	return hav[x].find(y)!=hav[x].end();
}
int getv(map<int,int> &t,int x){
	if(t.find(x)==t.end())return 0;
	return t[x];
}
char str[N];
int getu(int x,int y){
	if(!fd(x-1,y)){
		u[x][y]=x;
		return x;
	}
	if((!u[x][y])||(u[x][y]>x-1))u[x][y]=x-1;
	return u[x][y]=getu(u[x][y],y);
}
int getd(int x,int y){
	if(!fd(x+1,y)){
		d[x][y]=x;
		return x;
	}
	if((!d[x][y])||(d[x][y]<x+1))d[x][y]=x+1;
	return d[x][y]=getd(d[x][y],y);
}
int getl(int x,int y){
	if(!fd(x,y-1)){
		l[x][y]=y;
		return y;
	}
	if((!l[x][y])||(l[x][y]>y-1))l[x][y]=y-1;
	return l[x][y]=getl(x,l[x][y]);
}
int getr(int x,int y){
	if(!fd(x,y+1)){
		r[x][y]=y;
		return y;
	}
	if((!r[x][y])||(r[x][y]<y+1))r[x][y]=y+1;
	return r[x][y]=getr(x,r[x][y]);
}
void up(){
	sx--;
	if(fd(sx,sy)){
		sx=getu(sx,sy)-1;
	}
}
void down(){
	sx++;
	if(fd(sx,sy)){
		sx=getd(sx,sy)+1;
	}
}
void left(){
	sy--;
	if(fd(sx,sy))sy=getl(sx,sy)-1;
}
void right(){
	sy++;
	if(fd(sx,sy))sy=getr(sx,sy)+1;
}
void Main(){
	scanf("%d%d%d%d%d",&k,&n,&m,&sx,&sy);
	rep(i,1,max(n,m)){
		l[i].clear();
		r[i].clear();
		u[i].clear();
		d[i].clear();
		hav[i].clear();
	}
	hav[sx][sy]=1;
	scanf("%s",str+1);
	rep(i,1,k){
		if(str[i]=='N')up();
		if(str[i]=='S')down();
		if(str[i]=='W')left();
		if(str[i]=='E')right();
		//printf("%d %d\n",sx,sy);
		assert(!fd(sx,sy));
		hav[sx][sy]=1;
	}
	printf("Case #%d: %d %d\n",++cas,sx,sy);
}
int main(){
	scanf("%d",&t);
	while(t--)Main();
	return 0;
}





