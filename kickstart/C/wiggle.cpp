#include <iostream>
#include <vector>
#include <map>
#include <functional>

using namespace std;

typedef pair<int,int> pii; 

int main() {
	int T;
	cin >> T;
	for (int t=1; t<=T; ++t) {
		int n, r, c, sx, sy;
		cin >> n >> r >> c >> sx >> sy;
		sx--, sy--;
		map<pii, int> up, down, right, left;
		up[{sx,sy}] = sx-1;
		down[{sx,sy}] = sx+1;
		right[{sx,sy}] = sy+1;
		left[{sx,sy}] = sy-1;
		pii here = {sx, sy}; 
		string actions;
		cin >> actions;
		function<int(const pii &, char)> find_next = [&](const pii &here, char dir) { 
			if (dir == 'E') { 
				if (right.find(here) != right.end()) {
					int next = right[here];
					return right[here] = find_next({here.first, next}, dir);
				} else {
					return here.second;
				} 
			} else if (dir == 'W') { 
				if (left.find(here) != left.end()) {
					int next = left[here];
					return left[here] = find_next({here.first, next}, dir);
				} else {
					return here.second;
				}
			} else if (dir == 'N') { 
				if (up.find(here) != up.end()) {
					int next = up[here];
					return up[here] = find_next({next, here.second}, dir); 
				} else {
					return here.first;
				}
			} else if (dir == 'S') { 
				if (down.find(here) != down.end()) {
					int next = down[here];
					return down[here] = find_next({next, here.second}, dir);
				} else {
					return here.first;
				}
			}
		};
		for (char action : actions) {
			if (action == 'E') {
				here.second = right[here];
			} else if (action == 'W') {
				here.second = left[here];
			} else if (action == 'N') {
				here.first = up[here];
			} else if (action == 'S') {
				here.first = down[here];
			}
			right[here] = here.second+1;
			left[here] = here.second-1;
			up[here] = here.first-1;
			down[here] = here.first+1; 
			
			right[here] = find_next(here, 'E');
			left[here] = find_next(here, 'W');
			up[here] = find_next(here, 'N');
			down[here] = find_next(here, 'S'); 
		}
		cout << "Case #" << t << ": " << here.first+1 << ' ' << here.second+1 << endl;
	}
	return 0;
} 
