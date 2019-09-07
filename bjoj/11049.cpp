#include <iostream>
#include <vector>
#include <limits>

using namespace std;

typedef pair<int,int> pii;

const int INF = numeric_limits<int>::max(); 

int N;
vector<pii> arr(501);
int d[501][501]; // d[s][e]

int solve(int s, int e) {
	if (s == e) return 0;
	int &ret = d[s][e];
	if (ret) return ret; 
	ret = INF; 
	for (int i=s; i<e; ++i) {
		int cost = solve(s, i) + solve(i+1, e) + arr[s].first * arr[i].second * arr[e].second; 
		ret = min(ret, cost);
	}
	return ret;
} 

int main() {
	cin >> N;
	for (int i=0; i<N; ++i) {
		cin >> arr[i].first >> arr[i].second;
	}
	cout << solve(0, N-1); 
    return 0;
}

