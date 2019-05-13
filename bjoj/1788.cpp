#include <iostream>

using namespace std;

const long long int mod = 1e9;
const long long int pisano_period = 15 * 1e8;

long long int nth_fibo(long long int num) {
    long long int nth = num % pisano_period;
    if (nth == 0) return 0;
    if (nth == 1 || nth == 2) return 1;

    long long int fn1 = 1, fn2 = 1;
    long long int fn;
    for (int i=2; i<nth; ++i) {
        fn = (fn1 + fn2) % mod;
        fn2 = fn1;
        fn1 = fn;
    }
    return fn;
}

int main() {
    int num;
    cin >> num;
    if (num < 0 && num % 2 == 0) {
        cout << -1 << endl;
    } else if (num == 0) {
        cout << 0 << endl;
    } else {
        cout << 1 << endl;
    }
    if (num < 0) num *= -1;
    cout << nth_fibo(num);
    return 0;
}
