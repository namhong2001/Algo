#include <iostream>
#include <cstring>
#include <functional>
#include <vector>
#include <numeric>

using namespace std;

typedef long long ll;

int main() {
    int N, M;
    cin>>N>>M;
    ll street[1001];
    memset(street, 0, sizeof(street));
	int l_limit;
	int r_limit;
	vector<int> location(N+1);
    for(int i=0; i<N; ++i){
        ll D, W;
        cin>>D>>W;
		location[i+1] = D;
        street[D]+=W;
		if (i == 0) l_limit = D;
		if (i == N-1) r_limit = D;
    }
    vector<vector<vector<ll>>> cache(1001, vector<vector<ll>>(1001, vector<ll>(2, -1)));
    ll psum[1002];
	partial_sum(street, street+1001, psum);
    const ll INF=98765432198765;
    function<ll(int,int,int)> dp = [&](int l, int r, int flag) { 
        if (l == l_limit && r == r_limit) return 0ll;
        if (l < l_limit || r > r_limit) return INF;
        ll &ret = cache[l][r][flag];
        if (ret != -1) return ret;
        ll cost = psum[1000] - (psum[r] - (l?psum[l-1]:0));
		if (cost == 0) return 0ll;
        ll l_d = flag == 0 ? 1 : r-l+1;
        ll r_d = flag == 0 ? r-l+1 : 1;
        ret = min(dp(l-1, r, 0)+cost*l_d, dp(l, r+1, 1)+cost*r_d);
        return ret;
    };
    cout << dp(location[M], location[M], 0);

    return 0;
}
