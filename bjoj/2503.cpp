#include <iostream>
#include <vector>

using namespace std;

struct Game { 
	int a, b, c;
	int strike, ball;
};

bool ok(vector<Game> &arr, int num[3]) { 
	for (Game &g : arr) {
		int s = 0, b = 0;
		int g_n[3] = {g.a, g.b, g.c};
		for (int i=0; i<3; ++i) {
			if (g_n[i] == num[i]) s++;
		}
		for (int i=0; i<3; ++i) {
			for (int j=0; j<3; ++j) {
				if (i == j) continue;
				if (g_n[i] == num[j]) {
					b++;
					break;
				}
			}
		}
		if (s != g.strike || b != g.ball) {
			return false;
		}
	}
	return true;
} 

int main() {
	int N;
	cin >> N;
	vector<Game> arr(N);
	for (int i=0; i<N; ++i) {
		string num;
		int s, b; 
		cin >> num >> s >> b;
		int nn[3];
		for (int i=0; i<3; ++i) {
			nn[i] = num[i] - '0';
		} 
		arr[i] = {nn[0], nn[1], nn[2], s, b};
	}
	int ans = 0;
	for (int i=1; i<=9; ++i) {
		for (int j=1; j<=9; ++j) {
			if (i == j) continue;
			for (int k=1; k<=9; ++k) {
				if (j == k || i == k) continue;
				int num[3] = {i, j, k};
				if (ok(arr, num)) ans++; 
			}
		}
	} 
	cout << ans;
    return 0;
}

