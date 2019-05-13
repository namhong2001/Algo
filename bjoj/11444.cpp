#include <iostream>
#include <vector>
using namespace std;

const long long int mod = 1e9 + 7;

typedef vector<vector<long long>> matrix;
matrix operator * (const matrix &a, const matrix &b) {
    int n = a.size();
    matrix c(n, vector<long long>(n));
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            for (int k=0; k<n; ++k) {
                c[i][j] += a[i][k] * b[k][j] % mod;
            }
            c[i][j] %= mod;
        }
    }
    return c;
}

int main() {
    long long int n;
    cin >> n;
    matrix mul = {{1, 1}, {1, 0}};
    matrix result = {{1, 0}, {0, 1}};
    while(n > 0) {
        if (n%2 == 1) {
            result = result * mul;
        }
        mul = mul * mul;
        n /= 2;
    }
    cout << result[1][0];
    return 0;
}
