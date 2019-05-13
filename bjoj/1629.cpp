#include <iostream>

using namespace std;

int pow(int a, int n, int mod) {
    if (n == 0) return 1;
    long long int ret = pow(a, n/2, mod);
    ret = ret * ret % mod;
    if (n%2) ret = ret * a % mod;
    return ret;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << pow(a, b, c);
    return 0;
}
