#include <iostream>

using namespace std;

int main() {
    int n, l;
    cin >> n >> l;
    int a;
    while (l <= 100) {
        int inc_sum = l * (l-1) / 2;
        if (inc_sum > n) {
            l = 101;
            break;
        }
        if ((n-inc_sum) % l == 0) {
            a = (n-inc_sum) / l;
            break;
        }
        ++l;
    }
    if (l == 101) {
        cout << -1;
    } else {
        for (int i=0; i<l; ++i) {
            cout << a + i << ' ';
        }

    }

    return 0;
}
