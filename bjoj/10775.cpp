#include <bits/stdc++.h>

using namespace std;

struct UF {
    vector<int> parent, occupied;
    int size = 0;
    UF(int n): parent(n+1), occupied(n, 0) {
        for (int i=0; i<n+1; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }

    int merge(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return u;
        if (u < v) swap(u, v);
        parent[u] = v;
        return v;
    }

    bool add(int u) {
        int p = find(u);
        while(occupied[p]) {
            p--;
            p=find(p);
        }
        if (p == 0) return false;
        merge(p, u);
        ++size;
        occupied[p] = 1;
        return true;
    }
};


int main() {
    int G, P;
    cin >> G >> P;
    UF uf(G);
    for (int i=0; i<P; ++i) {
        int a;
        cin >> a;
        if (!uf.add(a)) {
            cout << uf.size;
            return 0;
        }
    }
    cout << uf.size;
    return 0;
}
