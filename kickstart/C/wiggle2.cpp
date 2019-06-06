#include <iostream>
#include <vector>
#include <set>
#include <functional>

using namespace std;

typedef pair<int,int> pii; 

int main() {
	int T;
	cin >> T;
	for (int t=1; t<=T; ++t) {
		int n, r, c, x, y;
		cin >> n >> r >> c >> x >> y;
		set<pii> rs[r+1], cs[c+1];
		rs[x].insert({y, y});
		cs[y].insert({x, x});
		string actions;
		cin >> actions;
		for (char action : actions) {
			if (action == 'E') {
				y = y+1;
				auto jump = rs[x].lower_bound({y, y});
				if (jump->first == y) y = jump->second+1; 
			} else if (action == 'W') {
				y = y-1;
				auto jump = rs[x].lower_bound({y, y});
				if (jump->first == y) y = jump->second+1; 
				auto lower = rs[x].lower_bound({y+1, y+1});
				if (lower->first == y+1) y = lower->second+1; 
				here.second = left[here];
			} else if (action == 'N') {
				here.first = up[here];
			} else if (action == 'S') {
				here.first = down[here];
			}
			right[here] = find_next(here, 'E');
			left[here] = find_next(here, 'W');
			up[here] = find_next(here, 'N');
			down[here] = find_next(here, 'S'); 
		}
		cout << "Case #" << t << ": " << here.first+1 << ' ' << here.second+1 << endl;
	}
	return 0;
} 

