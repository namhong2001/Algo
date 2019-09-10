#include <iostream>

using namespace std;

int main() {
	int cnt[7];
	for (int i=1; i<=6; ++i) cin >> cnt[i];
	int ans = 0;
	for (int i=6; i>=1; --i) {
		switch(i) {
			case 6:
				ans += cnt[6];
				break;
			case 5:
				ans += cnt[5];
				cnt[1] -= cnt[5] * 11;
				cnt[5] = 0;
				break;
			case 4:
				{
					ans += cnt[4];
					int cntof2 = cnt[4] * 5;
					if (cnt[2] >= cntof2) cnt[2] -= cntof2;
					else {
						cntof2 -= cnt[2];
						cnt[2] = 0;
						cnt[1] -= cntof2 * 4;
					} 
					cnt[4] = 0;
				}
				break;
			case 3: 
				{
					ans += cnt[3] / 4;
					int remain = cnt[3] % 4;
					if (remain) ans++;

					if (remain == 3) {
						if (cnt[2]) {
							cnt[2]--;
							cnt[1] -= 5;
						} else {
							cnt[1] -= 9;
						}
					} else if (remain == 2) {
						if (cnt[2] >= 3) {
							cnt[2] -= 3;
							cnt[1] -= 6;
						} else {
							int onecnt = 18;
							onecnt -= cnt[2] * 4;
							cnt[2] = 0;
							cnt[1] -= onecnt;
						}
					} else if (remain == 1) {
						if (cnt[2] >= 5) {
							cnt[2] -= 5;
							cnt[1] -= 7;
						} else {
							int onecnt = 27;
							onecnt -= cnt[2] * 4;
							cnt[2] = 0;
							cnt[1] -= onecnt;
						}
					}
				}
				break;
			case 2: 
				{
					ans += cnt[2] / 9;
					int remain = cnt[2] % 9; 

					if (remain) {
						ans++;
						int onecnt = 36; 
						onecnt -= remain * 4;
						cnt[1] -= onecnt;
					}
					cnt[2] = 0;
				}
				break;
			case 1: 
				{
					if (cnt[1] <= 0) break;
					ans += cnt[1] / 36;
					int remain = cnt[1] % 36;
					if (remain) {
						ans++;
					}
				}
				break;
		}
	}
	cout << ans; 
    return 0;
}

