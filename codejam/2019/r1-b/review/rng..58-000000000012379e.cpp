#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

int x[100010];
int y[100010];
	
void main2(void){
	int N,X;
	int i;
	
	cin >> N >> X;
	
	REP(i,X+5) x[i] = y[i] = 0;
	
	REP(i,N){
		int a,b;
		char c;
		scanf(" %d %d %c ", &a, &b, &c);
		
		if(c == 'S'){
			y[0]++;
			y[b]--;
		} else if(c == 'N'){
			y[b+1]++;
			y[X+1]--;
		} else if(c == 'E'){
			x[a+1]++;
			x[X+1]--;
		} else {
			x[0]++;
			x[a]--;
		}
	}
	
	REP(i,X) x[i+1] += x[i];
	REP(i,X) y[i+1] += y[i];
	
	int ax = 0, ay = 0;
	REP(i,X+1) if(x[i] > x[ax]) ax = i;
	REP(i,X+1) if(y[i] > y[ay]) ay = i;
	
	cout << ax << ' ' << ay << endl;
}	
	
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(void){
	int TC,tc;
	cin >> TC;
	REP(tc,TC){
		printf("Case #%d: ", tc + 1);
		main2();
	}
	return 0;
}
