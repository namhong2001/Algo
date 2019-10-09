#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

const ll MOD = 1e9+7;

ll d[1002][1002]; // d[group_cnt][remains] = cases 
ll solve(ll groups, ll remains) {
	if (remains == 0) return 1;
	ll &ret = d[groups][remains];
	if (ret != -1) return ret;
	ret = solve(groups, remains-1)*groups + solve(groups+1, remains-1);
	ret %= MOD;
	return ret;
}

int main() {
	int N;
	cin >> N;
	memset(d, -1, sizeof(d));
	cout << solve(0, N); 
    return 0;
}

