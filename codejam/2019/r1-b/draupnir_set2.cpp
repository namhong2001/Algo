#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

typedef long long ll;

int main() {
    int T, W;
    cin >> T >> W;
    for (int t=1; t<=T; ++t) {
        ll ans[6];
        int day = 200;
        cout << day << endl;
        ll r;
        cin >> r;
        for (int i=3; i<6; ++i) {
            ans[i] = r;
            for (int j=3; j<i; ++j) {
                ans[i] -= (ans[j]<<day/(j+1));
            }
            ans[i] >>= (day/(i+1));
        }
        day = 56;
        cout << day << endl;
        cin >> r;
        for (int i=3; i<6; ++i) {
            r -= (ans[i]<<day/(i+1));
        }
        for (int i=0; i<3; ++i) {
            ans[i] = r;
            for (int j=0; j<i; ++j) {
                ans[i] -= (ans[j]<<day/(j+1));
            }
            ans[i] >>= (day/(i+1));
        }

        for (int i=0; i<6; ++i) {
            cout << ans[i] << ' ';
        }
        cout << endl;
        int verdict;
        cin >> verdict;
        assert(verdict == 1);
    }

    return 0;
}
