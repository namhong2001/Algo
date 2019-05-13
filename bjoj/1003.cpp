#include <iostream>

using namespace std;
const int N_MAX = 40;

int zero_count[N_MAX+1] = {1, 0};
int one_count[N_MAX+1] = {0, 1};

int nth_zero(int n) {
    if (n == 0) return 1;
    if (n == 1) return 0;
    if (zero_count[n]) return zero_count[n];

    zero_count[n] = nth_zero(n-1) + nth_zero(n-2);
    return zero_count[n];
}

int nth_one(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (one_count[n]) return one_count[n];

    one_count[n] = nth_one(n-1) + nth_one(n-2);
    return one_count[n];
}


int main() {
    int zero_count[N_MAX+1] = {1, 0};
    int one_count[N_MAX+1] = {0, 1};
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << nth_zero(n) << ' ' << nth_one(n) << '\n';
    }
    return 0;
}
