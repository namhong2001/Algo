#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

typedef pair<int,int> pii; 

int main() {
	int N;
	cin >> N;
	vector<pii> arr(N);
	int sum = 0;
	for (int i=0; i<N; ++i) {
		int a;
		cin >> a;
		arr[i].first = a;
		arr[i].second = i+1;
		sum += a;
	}
	sort(arr.begin(), arr.end(), greater<pii>());
	int d[sum+1] = {};
	int ans = 0;
	bool used[N][sum+1] = {};
	vector<int> congress;
	for (int i=0; i<N; ++i) {
		int a = arr[i].first; 
		if (d[sum/2] + a > sum/2 && d[sum/2] + a > ans) {
			ans = d[sum/2] + a; 
			congress.clear();
			congress.push_back(arr[i].second);
			int s = sum/2;
			int here = i-1;
			while (here >= 0) {
				if (used[here][s]) {
					congress.push_back(arr[here].second);
					s -= arr[here].first;
				}
				here--;
			} 
		}
		for (int j=sum; j>=a; --j) { 
			if (d[j-a] + a > d[j]) {
				d[j] = d[j-a] + a;
				used[i][j] = true;
			}
		}
	} 
	cout << congress.size() << '\n';
	sort(congress.begin(), congress.end());
	for (int i : congress) cout << i << ' ';
	return 0;
}

