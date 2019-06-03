#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef pair<int,int> pii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	multiset<pii> ms;
	while (n--) {
		int s, t;
		cin >> s >> t;
		ms.insert({s, t});
	} 
	int ans = 0;
	while (!ms.empty()) {
		ans++; 
		auto here = ms.begin(); 
		int cur_end = here->second;
		ms.erase(here); 
		while (true) {
			auto next = ms.lower_bound({cur_end, 0});
			if (next == ms.end()) break;
			cur_end = next->second; 
			ms.erase(next);
		}
	}
	cout << ans << endl;
} 

