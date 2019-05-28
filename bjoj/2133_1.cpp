#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> d;

// teeth = {0(ooo), 1(oxx), 2(oox)}
int get_cnt(int width, int teeth) {
	if (width%2 && teeth == 0) return 0;
	if (width <= 1) return 1;
	int &ret = d[width][teeth];
	if (ret != -1) return ret; 
	if (teeth == 0) {
		return ret = get_cnt(width, 1) + get_cnt(width-1, 2) + get_cnt(width-2, 0);
	} else if (teeth == 1) { 
		return ret = get_cnt(width-1, 2);
	} else if (teeth == 2) {
		return ret = get_cnt(width-1, 0) + get_cnt(width-1, 1);
	}
	// unreachable
	return ret;
} 

int main() {
	int n;
	cin >> n;
	d.assign(n+1, vector<int>(3, -1)); 
	cout << get_cnt(n, 0) << endl;
	return 0;
}

