#include <iostream>

using namespace std;

const int mod = 1e6;
const int pisano_period = 15 * 1e5;

int nth_fibo(long long int num) {
    int nth = num % pisano_period;
    if (nth == 0) return 0;
    if (nth == 1 || nth == 2) return 1;

    int fn1 = 1, fn2 = 1;
    int fn;
    for (int i=2; i<nth; ++i) {
        fn = (fn1 + fn2) % mod;
        fn2 = fn1;
        fn1 = fn;
    }
    return fn;
}

int main() {
    long long int num;
    cin >> num;
    cout << nth_fibo(num);
    return 0;
}



