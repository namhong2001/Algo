#include <iostream>

using namespace std;

bool row[15];
bool col[15];
bool sum[30]; 
bool extract[30]; 

int n; 

int search(int x, int y) { 
	//cerr << x << ' ' << y << ' ' << cnt << endl;
	if (x == n-1) return 1;
	int ret = 0; 
	row[x] = true;
	col[y] = true;
	sum[x+y] = true;
	extract[y-x+n] = true;
	int nx = x+1; 
	for (int j=0; j<n; ++j) {
		if (col[j] || sum[nx+j] || extract[j-nx+n]) continue;
		ret += search(nx, j);
	}
	row[x] = false;
	col[y] = false;
	sum[x+y] = false;
	extract[y-x+n] = false; 
	return ret;
} 

int solve() {
	int ans = 0;
	for (int j=0; j<n; ++j) { 
		ans += search(0, j);
	}
	return ans;
} 

int main() {
	cin >> n;
	cout << solve();
	return 0;
} 
