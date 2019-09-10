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
	int d[101] = {};
	for (int i=1; i<=N; ++i) {
		for (int w=99; w>=hp[i]; --w) {
			d[w] = max(d[w], d[w-hp[i]] + joy[i]);
		}
	} 
	cout << d[99]; 
	return 0;
}

