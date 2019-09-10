#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

int N;
ll d[21][101];
ll arr[101];
ll solve(int sum, int nth) {
	if (sum > 20 || sum < 0) return 0;
	if (nth == N-2) {
		if (sum == arr[N-1]) return 1;
		else return 0;
	}
	ll &ret = d[sum][nth];
	if (ret != -1) return ret;
	ret = 0;
	ret += solve(sum + arr[nth+1], nth+1);
	ret += solve(sum - arr[nth+1], nth+1);
	return ret;
} 

int main() {
	memset(d, -1, sizeof(d));
	cin >> N; 
	for (int i=0; i<N; ++i) cin >> arr[i];
	cout << solve(arr[0], 0); 
	return 0;
}

