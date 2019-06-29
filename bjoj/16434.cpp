#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

typedef long long ll;
typedef tuple<ll,ll,ll> Room;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll N, ATK;
	cin >> N >> ATK;
	vector<Room> rooms(N);
	for (int i=0; i<N; ++i) {
		ll t, a, h;
		cin >> t >> a >> h; 
		rooms[i] = {t, a, h};
	}
	auto can_pass = [&](ll HP) {
		ll atk = ATK;
		ll hp = HP;
		for (Room &r : rooms) {
			ll t, a, h;
			tie(t, a, h) = r;
			if (t == 2) {
				atk += a;
				hp = min(hp+h, HP);
			} else if (t == 1) { 
				ll monster_turn = (h-1)/atk+1;
				ll my_turn = (hp-1)/a+1;
				if (monster_turn > my_turn) {
					return false;
				}
				hp -= a*(monster_turn-1);
			}
		}
		return true;
	};
	ll l = 1, r = 1e18;
	while (l < r) {
		ll mid = (l+r)/2;
		if (can_pass(mid)) r = mid;
		else l = mid+1;
	}
	cout << l << '\n';
	return 0; 
} 
