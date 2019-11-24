#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> in;
vector<int> bit;
vector<int> lastIndex;
int N;

void add(int index, int delta) {
    if (index == 0) return;
    for (int i=index; i<=N; i += i&-i) {
        bit[i] += delta;
    }    
}

int sum(int r) {
    int ret = 0;
    for (int i=r; i>0; i -= i&-i) {
        ret += bit[i];
    }
    return ret;
}

int sum(int l, int r) {
    return sum(r) - sum(l-1);
}

struct query {
    int l, r, index;
    bool operator < (const query &rhs) const {
        return r < rhs.r;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    in.assign(N+1, 0);
    bit.assign(N+1, 0);
    lastIndex.assign((int)1e6+1, 0);
    for (int i=1; i<=N; ++i) cin >> in[i];
    int Q;
    cin >> Q;
    vector<query> q(Q);
    for (int i=0; i<Q; ++i) {
        cin >> q[i].l >> q[i].r;
        q[i].index = i;
    }
    sort(q.begin(), q.end());
    vector<int> ans(Q);
    int cursor = 1;
    for (int i=0; i<Q; ++i) {
        while (cursor <= q[i].r) {
            add(lastIndex[in[cursor]], -1);
            lastIndex[in[cursor]] = cursor;
            add(cursor, 1);
            cursor++;
        }
        ans[q[i].index] = sum(q[i].l, q[i].r);
    }
    for (int a : ans) {
        cout << a << '\n';
    }
    return 0;
}