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
        for (int i=5; i>=0; --i) {
            int day = i*63;
            if (day == 0) day = 1;
            cout << day << endl;
            ll r;
            cin >> r;
            for (int j=i+1; j<6; ++j) {
                r -= ans[j]*pow(2, day/(j+1));
            }
            ans[i] = r / pow(2, day/(i+1));
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
