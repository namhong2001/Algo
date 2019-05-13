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

typedef long long ll;
	
void main2(void){
	cout << 56 << endl;
	fflush(stdout);
	ll x;
	cin >> x;
	cout << 168 << endl;
	fflush(stdout);
	ll y;
	cin >> y;
	
	ll one = (x >> 56);
	x %= (1ll<<56);
	
	ll two = (x >> 28);
	x %= (1ll<<28);
	
	ll three = (y >> 56);
	y %= (1ll<<56);
	
	ll four = (y >> 42);
	y %= (1ll<<42);
	
	x -= (three << 18);
	x -= (four << 14);
	
	ll a4b1 = (x >> 9);
	ll a32b1 = (y >> 28);
	
	ll five = (a32b1 - a4b1) / 28;
	ll six = a4b1 - 4 * five;
	
	cout << one << ' ' << two << ' ' << three << ' ' << four << ' ' << five << ' ' << six << endl;
	fflush(stdout);
	
	int tmp;
	cin >> tmp;
}
	
int main(void){
	int T,W;
	cin >> T >> W;
	
	int t;
	REP(t,T) main2();
	
	return 0;
}
