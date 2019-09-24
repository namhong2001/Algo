#include <iostream>
#include <algorithm> 

using namespace std;

int main() {
	int N;
	cin >> N;
	int inc = 0, dec = 0;
	int last;
	int ans = 0;
	for (int i=0; i<N; ++i) {
		int a;
		cin >> a;
		if (i == 0) { 
			inc = 1, dec = 1;
			last = a;
			ans = max({ans, inc, dec});
		} else {
			if (a == last) {
				inc++, dec++;
			} else if (a > last) {
				inc++;
				dec = 1;
			} else if (a < last) {
				dec++;
				inc = 1;
			}
			ans = max({ans, inc, dec});
			last = a;
		}
	}
	cout << ans; 
    return 0;
}

