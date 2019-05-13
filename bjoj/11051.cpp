#include <iostream>
#include <vector>


using namespace std;
const int mod = 10007;
const int N_MAX = 1000;
vector<int> primes;

int biono_coefi(int n, int k) {
    int numerator[n-k];
    vector<int> denominator_primes;
    int ret = 1;
    for (int i=k+1; i<=n; ++i) {
        numerator[i-k-1] = i;
    }
    for (int i=1; i<=n-k; ++i) {
        int num = i;
        int j = 0;
        while (num > 1) {
            if (num % primes[j] == 0) {
                num /= primes[j];
                denominator_primes.push_back(primes[j]);
            } else {
                ++j;
            }
        }
    }
    for (auto dividor : denominator_primes) {
        for (int i=0; i<n-k; ++i) {
            if (numerator[i] % dividor == 0) {
                numerator[i] /= dividor;
                break;
            }
        }
    }
    for (int i=0; i<n-k; ++i) {
        ret = ret * numerator[i] % mod;
    }
    return ret;
}

void init_primes() {
    bool flag[N_MAX+1] = {false};
    flag[0] = flag[1] = true;
    for (int i=2; i<=N_MAX; ++i) {
        if (flag[i] == false) {
            primes.push_back(i);
        }
        for (int j = i*i; j<=N_MAX; j += i) {
            flag[j] = true;
        }
    }
}

int main() {
    init_primes();
    int n;
    int k;
    cin >> n >> k;
    cout << biono_coefi(n, k);
    return 0;
}
