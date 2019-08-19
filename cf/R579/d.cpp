#include <iostream>
#include <vector>

using namespace std;

int main() {
	string s, t;
	cin >> s >> t; 
	vector<int> lpos(s.size(), -1);
	vector<int> rpos(s.size(), -1);
	int tp = 0;
	for (int i=0; i<(int)s.size(); ++i) {
		if (tp < (int)t.size() && s[i] == t[tp]) {
			lpos[i] = tp;
			tp++;
		} else { 
			if (i > 0) lpos[i] = lpos[i-1];
		}
	}
	tp = (int)t.size()-1;
	for (int i=(int)s.size()-1; i>=0; --i) {
		if (tp >= 0 && s[i] == t[tp]) {
			rpos[i] = tp;
			tp--; 
		} else { 
			if (i < (int)s.size()-1) rpos[i] = rpos[i+1];
		}
	}
	int l = -1, r = -1;
	int ans = 0;
	while (l < (int)s.size()-1) { 
		//cerr << l << ' ' << r << endl;
		if (r == -1) {
			ans = max(ans, r-l-1);
			if (r < (int)s.size()-1) r++;
			else break;
		} else if (l == -1) {
			if (rpos[r] == 0) { 
				ans = max(ans, r-l-1);
				if (r < (int)s.size()-1) r++;
				else break;
			} else {
				l++;
			}
		} else if (rpos[r] <= lpos[l]+1) { 
			ans = max(ans, r-l-1);
			if (r < (int)s.size()-1) r++;
			else break;
		} else {
			l++;
		}
	} 
	cout << ans << endl; 
	return 0;
}

