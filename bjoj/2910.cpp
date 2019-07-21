#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <algorithm>

using namespace std; 

typedef pair<int,int> pii;

int main() {
	int N, C;
	cin >> N >> C;
	map<int,int> cnt;
	map<int,int> index;
	vector<int> inputs(N+1);
	for (int i=1; i<=N; ++i) { 
		int a;
		cin >> a; 
		inputs[i] = a;
		cnt[a]++;
		if (index[a] == 0) {
			index[a] = i;
		} 
	}
	vector<pii> arr;
	for (auto item : cnt) {
		int num, c;
		tie(num, c) = item;
		arr.emplace_back(c, -index[num]);
	}
	sort(arr.begin(), arr.end(), greater<pii>());
	for (auto a : arr) {
		int num = inputs[-a.second]; 
		for (int i=0; i<a.first; ++i) {
			cout << num << ' ';
		}
	}
	return 0;
} 
