#include <bits/stdc++.h>

using namespace std;

struct UF {
    vector<int> parent, rank, size;
    UF(int n): parent(n), rank(n, 0), size(n, 1) {
        for (int i=0; i<n; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }

    int merge(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return size[u];
        if (rank[u] > rank[v]) swap(u, v);
        if (rank[u] == rank[v]) rank[v]++;
        parent[u] = v;
        size[v] += size[u];
        return size[v];
    }
};

struct Indexer {
    unordered_map<string, int> matcher;
    int baseIndex;
    Indexer(): baseIndex(1) {}

    int getIndex(const string& str) {
        if (matcher[str]) return matcher[str];
        matcher[str] = baseIndex++;
        return matcher[str];
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c;
    cin >> c;
    while (c--) {
        int f;
        cin >> f;
        UF uf(2*f+1);
        Indexer idxer;
        while (f--) {
            string a, b;
            cin >> a >> b;
            cout << uf.merge(idxer.getIndex(a), idxer.getIndex(b)) << '\n';
        }
    }

    return 0;
}
