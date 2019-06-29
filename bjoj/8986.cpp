#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

int N;

ll get_moves(vector<ll> &arr, ll factor) {
	ll ret = 0;
	for (int i=0; i<N; ++i) {
		ret += abs(arr[i] - factor*i);
	}
	return ret;
}


int main() {
	cin >> N;
	vector<ll> in(N); 
	ll sum = 0;
	ll divider = 0;
	for (int i=0; i<N; ++i) {
		cin >> in[i];
		sum += in[i];
		divider += i;
	} 
	ll factor = roundl(1.0l*sum/divider);

	ll ans = min({get_moves(in, factor-1), get_moves(in, factor), get_moves(in, factor+1)}); 
	cout << ans << endl;
	return 0;
} 
