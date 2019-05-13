#include <iostream>
#include <vector>
#include <utility>

using namespace std;

struct UF {
    vector<int> parent, rank;
    UF(int n): parent(n), rank(n, 0) {
        for (int i=0; i<n; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }

    void merge(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return;

        if (rank[u] > rank[v]) swap(u, v);
        if (rank[u] == rank[v]) rank[v]++;
        parent[u] = v;
        return;
    }

    bool isInSameSet(int u, int v) {
        return find(u) == find(v);
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    UF uf(n+1);
    while(m--) {
        int action, a, b;
        cin >> action >> a >> b;
        switch(action) {
            case 0:
                uf.merge(a, b);
                break;
            case 1:
                cout << (uf.isInSameSet(a, b) ? "YES" : "NO") << '\n';
                break;
            default:
                break;
        }
    }
}
