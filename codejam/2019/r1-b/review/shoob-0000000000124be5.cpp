#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int ntest, lim;
    cin >> ntest >> lim;
    while (ntest--) {
        long long a[7];
        cout << 224 << endl;
        long long ans;
        cin >> ans;
        a[4] = (ans >> 56) % 128;
        a[5] = (ans >> 44) % 128;
        a[6] = (ans >> 37) % 128;
        cout << 48 << endl;
        cin >> ans;
        ans -= (a[4] << 12);
        ans -= (a[5] << 9);
        ans -= (a[6] << 8);
        a[1] = (ans >> 48) % 128;
        a[2] = (ans >> 24) % 128;
        a[3] = (ans >> 16) % 128;
        
        cout << a[1] << ' ' << a[2] << ' ' << a[3] << ' ' << a[4] << ' ' << a[5] << ' ' << a[6] << endl;
        cin >> ans;
        if (ans == -1) return 3;
    }
    return 0;
}
