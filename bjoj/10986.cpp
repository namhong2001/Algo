#include <iostream>

using namespace std;

const int M_MAX = 1000;
int remains[M_MAX] = {1};
int n, m;

int main() {
    cin >> n >> m;
    int sum = 0;
    for (int i=0; i<n; ++i) {
        int a;
        cin >> a;
        sum = (sum + a) % m;
        remains[sum]++;
    }
    long long ans = 0;
    for (int i=0; i<m; ++i) {
        if (remains[i] < 2) continue;
        ans += (long long)remains[i] * (remains[i]-1) / 2;
    }
    cout << ans;
    return 0;
}
