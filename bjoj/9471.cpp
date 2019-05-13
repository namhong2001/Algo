#include <iostream>

using namespace std;

int pisano_period(int m) {
    int pn1 = 1, pn2 = 1;
    int period = 0;
    do {
        int pn = (pn1 + pn2) % m;
        pn1 = pn2;
        pn2 = pn;
        period++;
    } while (!(pn1 == 1 && pn2 == 1));
    return period;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        cout << n << ' ' << pisano_period(m) << '\n';
    }
    return 0;
}
