#include <bits/stdc++.h>

using namespace std;

const int N_MAX = 2e5;
const int MOD = 1e9+7;

struct Fenwick {
    vector<long long> arr;
    Fenwick(): arr(N_MAX+1) {}

    void add(int p, int v) {
        ++p;
        while(p<arr.size()) {
            arr[p] += v;
            p += p & -p;
        }
    }
    long long sum(int p) {
        ++p;
        long long ret = 0;
        while (p > 0) {
            ret += arr[p];
            p &= p-1;
        }
        return ret;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    Fenwick pos, size;
    long long ans = 0;
    for (int i=0; i<n; ++i) {
        int a;
        cin >> a;
        long long cost =
            size.sum(a-1)*a-pos.sum(a-1) +
            pos.sum(N_MAX-1)-pos.sum(a)-(size.sum(N_MAX-1)-size.sum(a))*a;
        cost %= MOD;
        if (!ans) ans = cost;
        else ans = ans*cost % MOD;
        pos.add(a, a);
        size.add(a, 1);
    }
    cout << ans;
    return 0;
}
