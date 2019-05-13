#include <bits/stdc++.h>

using namespace std;

struct Fenwick {
    vector<int> arr;
    Fenwick(int n): arr(n+1) {}

    void add(int p, int v){
        while(p<arr.size()) {
            arr[p] += v;
            p += p & -p;
        }
    }

    long long sum(int p) {
        long long ret = 0;
        while (p > 0) {
            ret += arr[p];
            p &= p-1;
        }
        return ret;
    }

    void change(int p, int v) {
        long long origin = sum(p)-sum(p-1);
        add(p, v-origin);
    }
};

int toRefined(int n) {
    const int minus = 1;
    const int plus = 0;
    const int zero = -1e5;

    if (n > 0) return plus;
    if (n == 0) return zero;
    if (n < 0) return minus;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    while(cin >> n >> k) {
        Fenwick fw(n);
        for (int i=1; i<=n; ++i) {
            int x;
            cin >> x;
            fw.add(i, toRefined(x));
        }
        for (int i=0; i<k; ++i) {
            char action;
            int a, b;
            cin >> action >> a >> b;

            switch(action) {
                case 'C':
                    fw.change(a, toRefined(b));
                    break;
                case 'P': {
                    long long product = fw.sum(b) - fw.sum(a-1);
                    if (product < 0) cout << '0';
                    else if (product % 2) cout << '-';
                    else cout << '+';
                    break;
                }
                default:
                    break;
            }
        }
        cout << '\n';
    }


    return 0;
}
