#include <iostream> 

using namespace std;

typedef long long ll;

int main() {
	string s;
	cin >> s;
	int total_v = 0;
	int v_cnt = 0;
	for (int i=0; i<(int)s.size(); ++i) {
		if (s[i] == 'v') {
			v_cnt++;
		} else if (s[i] == 'o') {
			if (v_cnt >= 2) {
				total_v += v_cnt-1;
			}
			v_cnt = 0;
		}
	}
	if (v_cnt >= 2) {
		total_v += v_cnt-1;
	}
	v_cnt = 0;
	
	
	ll ans = 0; 
	int cur_v = 0; 
	for (int i=0; i<(int)s.size(); ++i) { 
		if (s[i] == 'v') {
			v_cnt++;
		} else if (s[i] == 'o') {
			if (v_cnt >= 2) {
				cur_v += v_cnt-1; 
			}
			ans += 1ll*cur_v*(total_v-cur_v); 
			v_cnt = 0;
		}
	}
	cout << ans << endl; 
	return 0;
}
