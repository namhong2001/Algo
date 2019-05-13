#include <bits/stdc++.h>

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
};

int main() {
    int n, m;
    cin >> n >> m;
    UF uf(n);
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            int conn;
            cin >> conn;
            if (conn && i > j) {
                uf.merge(i, j);
            }
        }
    }

    if (m <= 0) cout << "NO";
    else  {
        int canTravel = true;
        int a;
        cin >> a;
        int p = uf.find(a-1);
        for (int i=1; i<m; ++i) {
            cin >> a;
            if (uf.find(a-1) != p) {
                canTravel=false;
                break;
            }
        }
        cout << (canTravel ? "YES" : "NO");
    }

    return 0;
}
