#include <iostream>

using namespace std; 

int joy[21];
int hp[21];

int main() {
	int N;
	cin >> N;
	for (int i=1; i<=N; ++i) {
		cin >> hp[i];
	}
	for (int i=1; i<=N; ++i) {
		cin >> joy[i];
	}
	int d[21][101] = {};
	for (int i=1; i<=N; ++i) {
		for (int w=0; w<100; ++w) {
			if (w < hp[i]) d[i][w] = d[i-1][w];
			else d[i][w] = max(d[i-1][w], d[i-1][w-hp[i]] + joy[i]);
		}
	} 
	cout << d[N][99]; 
	return 0;
}

