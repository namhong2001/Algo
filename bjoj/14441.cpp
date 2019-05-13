#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<vector<ll>> matrix;
ll MOD;

matrix operator * (const matrix &a, const matrix &b) {
    int n = a.size();
    matrix c(n, vector<ll>(n, 0));
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            for (int k=0; k<n; ++k) {
                c[i][j] += a[i][k] * b[k][j];
                c[i][j] %= MOD;
            }
        }
    }
    return c;
}

matrix operator + (const matrix &a, const matrix &b) {
    int n = a.size();
    matrix c(n, vector<ll>(n, 0));
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            c[i][j] = (a[i][j] + b[i][j]) % MOD;
        }
    }
    return c;
}

matrix identity(int n) {
    matrix ret(n, vector<ll>(n, 0));
    for (int i=0; i<n; ++i) {
        ret[i][i] = 1;
    }
    return ret;
}

matrix pow(matrix &a, int n) {
    if (n == 1) return a;

    matrix half = pow(a, n/2);
    if (n%2) {
        return half * half * a;
    } else {
        return half * half;
    }
}

matrix exp_sum(matrix &a, int n) {
    if (n == 1) return a;
    if (n%2) {
        return exp_sum(a, n-1) * a + a;
    } else {
        return exp_sum(a, n/2) * (identity(a.size()) + pow(a, n/2));
    }
}

int main() {
    ll n, k, m;
    cin >> n >> k >> m;
    MOD = m;
    matrix a(n, vector<ll>(n));
    for (int i=0; i<n; ++i) {
        string s;
        cin >> s;
        for (int j=0; j<n; ++j) {
            a[i][j] = s[j] == 'Y' ? 1 : 0;
        }
    }
    matrix sum = exp_sum(a, k-1);
    ll ans = 0;
    for (int i=0; i<n; ++i) {
        ans += sum[i][i];
    }
    ans %= MOD;
    cout << ans << endl;
    return 0;
}
