#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

int n, m;
map<string,int> name_order;
vector<ll> can_eat; 
int best; 
map<ll, int> cache;

void search(ll foods, ll eat) { 
	int food_cnt = __builtin_popcount(foods);
	if (eat == (1ll<<n)-1) {
		best = min(best, food_cnt);
		return;
	}
	if (food_cnt >= best-1) return; 
	if (cache.find(eat) != cache.end()) {
		if (food_cnt >= cache[eat]) return;
	} 
	cache[eat] = food_cnt; 
	for (int i=0; i<m; ++i) {
		if (foods & 1ll<<i) continue;
		search(foods|1ll<<i, eat|can_eat[i]);
	}
} 

int solve() {
	best = 51;
	cache.clear();
	search(0, 0); 
	return best;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		name_order.clear();
		can_eat.clear();
		can_eat.resize(m);
		for (int i=0; i<n; ++i) {
			string s;
			cin >> s;
			name_order[s] = i;
		} 
		for (int i=0; i<m; ++i) {
			int cnt;
			cin >> cnt;
			ll eat = 0;
			while (cnt--) {
				string name;
				cin >> name;
				eat |= 1ll<<name_order[name];
			}
			can_eat[i] = eat;
		}
		cout << solve() << endl;
	}
	return 0;
} 
