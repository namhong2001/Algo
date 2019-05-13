#include <iostream>

using namespace std;

const long long int mod = 1e9;
const long long int pisano_period = 15 * 1e8;

long long int *nth_fibo(long long int first, long long int second) {
    long long int max_nth;
    long long int min_nth;
    long long int first_nth = min_nth = first % pisano_period;
    long long int second_nth = max_nth = second % pisano_period;

    if (first_nth > second_nth) {
        min_nth = second_nth;
        max_nth = first_nth;
    }

    long long int ret[2];

    if (nth == 0) return 0;
    if (nth == 1 || nth == 2) return ret;

    long long int fn1 = 1, fn2 = 1;
    long long int fn;
    for (int i=2; i<max_nth; ++i) {
        if (i == min_nth) {
            ret[0] = fn;
        }
        fn = (fn1 + fn2) % mod;
        fn2 = fn1;
        fn1 = fn;
    }
    ret[1] = fn;
    return ret;
}

long long int fibo_sum(long long int start, long long int end) {
    return nth_fibo(num+2)-1;
}

int main() {
    long long int a, b;
    cin >> a >> b;
    cout << (fibo_sum(b) - fibo_sum(a-1) + mod) % mod;
    return 0;
}
