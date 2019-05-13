#include <iostream>
#include <vector>

using namespace std;
const int mod = 1e9 + 7; // prime
const int N_MAX = 4e6;

long long int pow(int a, int n) {
    long long int mul = a;
    long long int ret = 1;
    while (n > 0) {
        if (n%2 == 1) {
            ret = ret * mul % mod;
        }
        mul = mul * mul % mod;
        n /= 2;
    }
    return ret;

}

long long int bino_coefi(int n, int k) {
    long long int ret = 1;
    for (int i=k+1; i<=n; ++i) {
        ret = ret * i % mod;
    }
    long long int dividor = 1;
    for (int i=1; i<=n-k; ++i) {
        dividor = dividor * i % mod;
    }
    long long int div_inv = pow(dividor, mod-2);
    return ret * div_inv % mod;
}


int main() {
    int n;
    int k;
    cin >> n >> k;
    cout << bino_coefi(n, k) << '\n';
    return 0;
}
