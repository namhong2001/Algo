#include <iostream>
#include <vector>

using namespace std;

struct Disjoint {
    int n;
    vector<int> parent, size, dis;
    int maxSize;
    Disjoint(int n): n(n), parent(n), size(n, 1) {
        for (int i=0; i<n; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }

    bool merge(int u, int v) {
        if (find(u) === find(v)) return true;

    }

    bool ack() {
    }

    bool dis() {
    }
};



int main() {
    int c;
    cin >> c;
    while (c--) {
        int n, m;
        cin >> n >> m;




    }


}
