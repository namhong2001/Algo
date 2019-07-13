#include <iostream>

using namespace std;

int main() {
	string A, B; 
	cin >> A >> B;
	int ans = 60;
	for (int s=0; s<=(int)B.size()-(int)A.size(); ++s) {
		int cnt = 0;
		for (int i=0; i<(int)A.size(); ++i) {
			if (A[i] != B[s+i]) cnt++;
		}
		ans = min(ans, cnt);
	}
	cout << ans << endl;
	return 0;
} 
