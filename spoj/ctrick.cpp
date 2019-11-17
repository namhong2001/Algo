#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> bit;
int sum(int r) { // one-based
    int ret = 0;
    while (r > 0) {
        ret += bit[r];
        r -= r & -r;
    }
    return ret;
}

int sum(int l, int r) { // zero-based
    r %= N;
    l++, r++;
    if (l > r) {
        if (l-r == 1) return sum(N);
        else return sum(N) - sum(r, l-2);
    }
    return sum(r) - sum(l-1);
}

void add(int idx, int delta) { // one-based
    while (idx <= N) {
        bit[idx] += delta;
        idx += idx & -idx;
    }
}

int forward(int cur, int cnt) { // zero-based
    int round = sum(N);
    cnt %= round;
    if (cnt == 0) cnt = round;
    int l = 0, r = N-1; // think addions to cur, l = false, r = true
    while (l+1 < r) {
        int mid = (l+r)/2;
        if (sum(cur, cur+mid) >= cnt) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return (cur+r)%N;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> N;
        if (N == 1) {
            cout << 1 << '\n';
            continue;
        } else if (N == 2) {
            cout << "2 1" << '\n';
            continue;
        }
        bit.assign(N+1, 0);
        for (int i=1; i<=N; ++i) {
            add(i, 1);
        }
        vector<int> ans(N);
        ans[1] = 1;
        int index = 1;
        add(2, -1);
        for (int i=2; i<=N; ++i) {
            index = forward(index, i+1);
            ans[index] = i;
            add(index+1, -1);
        }
        for (int a : ans) {
            cout << a << " ";
        }
        cout << '\n';
    }
    return 0;
}