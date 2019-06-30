#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin >> N;
	vector<int> len(N);
	ll sum = 0;
	for (int i=0; i<N; ++i) {
		cin >> len[i];
		sum += len[i];
	}
	sort(len.begin(), len.end(), greater<int>());
	ll r = sum - len[0]; 
	cout << sum - 2*r +1;
	return 0;
} 
