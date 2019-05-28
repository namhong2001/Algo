#include <iostream>
#include <cstring>
#include <functional>
#include <vector>
#include <numeric>

using namespace std;

typedef long long ll;
const ll INF=98765432198765;

int main() {
    int N, M;
    cin>>N>>M;
	vector<ll> location(N);
	vector<ll> weight(N);
    for(int i=0; i<N; ++i){
        ll D, W;
        cin>>D>>W;
		location[i] = D;
		weight[i] = W;
    } 
    vector<vector<vector<ll>>> cache(N, vector<vector<ll>>(N, vector<ll>(2, -1)));
	vector<ll> psum(N+1);
	partial_sum(weight.begin(), weight.end(), psum.begin()+1);
    function<ll(int,int,int)> dp = [&](int l, int r, int where) { 
		if (l == 0 && r == N-1) return 0ll;
        if (l < 0 || r > N-1) return INF;
        ll &ret = cache[l][r][where];
        if (ret != -1) return ret;
		ret = INF;
        ll cost = psum[N] - (psum[r+1] - psum[l]); 
		ll here = where == 0 ? location[l] : location[r];
		if (l > 0) { // to left 
        	ll dist = here - location[l-1];
			ret = min(ret, dp(l-1, r, 0)+cost*dist);
		}
		if (r < N-1) { // to right
			ll dist = location[r+1] - here;
			ret = min(ret, dp(l, r+1, 1)+cost*dist);
		}
        return ret;
    };
    cout << dp(M-1, M-1, 0);

    return 0;
}
