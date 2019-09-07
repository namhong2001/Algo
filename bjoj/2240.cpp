#include <iostream>
#include <cstring>

using namespace std;

int T, W;
int d[1001][31][2];
int arr[1001]; 

int solve(int t, int w, int pos) {
	if (w < 0 || t >= T) return 0;
	int &ret = d[t][w][pos];
	if (ret != -1) return ret; 
	ret = 0;
	ret = max(solve(t+1, w-1, pos^1), solve(t+1, w, pos));
	if (pos == arr[t]) ret++;
	return ret;
} 

int main() {
	cin >> T >> W; 
	for (int i=0; i<T; ++i) {
		cin >> arr[i];
		arr[i]--;
	}
	memset(d, -1, sizeof(d));
	cout << max(solve(0, W, 0), solve(0, W-1, 1)); 
    return 0;
}

