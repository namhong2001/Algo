#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t=1; t<=T; ++t) {
        int n;
        cin >> n;
        vector<int> odd;
        vector<int> even;
        for (int i=0; i<n; ++i) {
            int a;
            cin >> a;
            if (i%2) odd.push_back(a);
            else even.push_back(a);
        }
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());
        int ans = -1;
        for (int i=0; i<n-1; ++i) {
            if (i%2) {
                if (odd[i/2] > even[i/2+1]) {
                    ans = i;
                    break;
                }
            } else {
                if (even[i/2] > odd[i/2]) {
                    ans = i;
                    break;
                }
            }
        }
        if (ans == -1) {
            cout << "Case #" << t << ": " << "OK" << endl;
        } else {
            cout << "Case #" << t << ": " << ans << endl;
        }
    }

    return 0;
}
