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
		function<int(pair<int,int>,int)> find_next = [&](const pii &here, char dir) { 
			if (dir == 'E') { 
				int next = here.second+1; 
				if (right.find({here.first, next}) != right.end()) {
					return right[here] = find_next({here.first, next}, dir);
				} else {
					return next;
				}
			} else if (dir == 'W') { 
				int next = here.second-1; 
				if (left.find({here.first, next}) != left.end()) {
					return left[here] = find_next({here.first, next}, dir);
				} else {
					return next;
				}
			} else if (dir == 'N') { 
				int next = here.first-1; 
				if (up.find({next, here.second}) != up.end()) {
					return up[here] = find_next({next, here.second}, dir);
				} else {
					return next;
				}
			} else if (dir == 'S') { 
				int next = here.first+1; 
				if (down.find({next, here.second}) != down.end()) {
					return down[here] = find_next({next, here.second}, dir);
				} else {
					return next;
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
			right[here] = find_next(here, 'E');
			left[here] = find_next(here, 'W');
			up[here] = find_next(here, 'N');
			down[here] = find_next(here, 'S'); 
		}
		cout << "Case #" << t << ": " << here.first+1 << ' ' << here.second+1 << endl;
	}
	return 0;
} 
