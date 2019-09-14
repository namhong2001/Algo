#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std; 

typedef pair<int,int> pii; 

const int INF = 987654321;

int main() {
	int N;
	cin >> N;
	vector<pii> arr(N+1);
	arr[0] = {INF, 0};
	int sum = 0;
	for (int i=1; i<=N; ++i) {
		int a;
		cin >> a;
		arr[i] = {a, i};
		sum += a;
	}
	sort(arr.begin(), arr.end(), greater<pii>());
	int ans = 0;
	int index[sum+1] = {}; 
	memset(index, -1, sizeof(index));
	index[0] = 0;
	for (int i=1; i<=N; ++i) {
		int a = arr[i].first;
		for (int j=sum; j>=a; --j) { 
			if (index[j] == -1 && index[j-a] != -1) {
				index[j] = i;
				if (j-a <= sum/2 && j > sum/2) {
					ans = max(ans, j);
				}
			}
		}
	} 
	vector<int> congress;
	while (ans) {
		int here = index[ans];
		congress.push_back(arr[here].second);
		ans -= arr[here].first;
	} 
	cout << congress.size() << '\n';
	sort(congress.begin(), congress.end());
	for (int i : congress) cout << i << ' ';
	return 0;
}

