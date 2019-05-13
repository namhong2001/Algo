#include <iostream>

using namespace std;

int biono_coefi(int n, int k) {
    int ret = 1;
    for (int i=k+1; i<=n; ++i) {
        ret *= i;
    }
    for (int i=1; i<=n-k; ++i) {
        ret /= i;
    }
    return ret;
}

int main() {
    int n;
    int k;
    cin >> n >> k;
    cout << biono_coefi(n, k);
    return 0;
}
