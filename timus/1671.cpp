#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>

using namespace std;

typedef pair<int,int> pii;

vector<int> r;
int f(int a) {
    return r[a] = r[a] == a ? a : f(r[a]);
}

void u(int a, int b) { 
    a = f(a), b = f(b);
    r[a] = b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, M;
    cin >> N >> M;
    r.resize(N+1);
    iota(r.begin(), r.end(), 0);
    vector<pii> threads(M+1);
    for (int i=1; i<=M; ++i) {
        cin >> threads[i].first >> threads[i].second;
    }
    int Q;
    cin >> Q;
    vector<int> queries(Q);
    vector<int> isQueryTarget(M+1, false);
    for (int i=0; i<Q; ++i) {
        cin >> queries[i];
        isQueryTarget[queries[i]] = true;
    }
    for (int i=1; i<=M; ++i) {
        if (isQueryTarget[i]) continue;
        u(threads[i].first, threads[i].second);
    }
    set<int> pieces;
    for (int i=1; i<=N; ++i) {
        pieces.insert(f(i));
    }
    vector<int> ans;
    reverse(queries.begin(), queries.end());
    for (int q : queries) {
        ans.push_back(pieces.size());
        int a = f(threads[q].first);
        int b = f(threads[q].second);
        u(a, b);
        pieces.erase(a);
        pieces.erase(b);
        pieces.insert(f(a));
    }
    reverse(ans.begin(), ans.end());
    for (int a : ans) {
        cout << a << ' ';
    }
    return 0;
}