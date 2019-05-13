#include <iostream>
#include <vector>

using namespace std;

void makeUpParent(vector<vector<int>> &edges, vector<int> &parent, int myIdx) {
    vector<int> &children = edges[myIdx];
    for (int i=0; i<children.size(); ++i) {
        int childIdx = children[i];
        if (childIdx == parent[myIdx]) continue;
        parent[childIdx] = myIdx;
        makeUpParent(edges, parent, childIdx);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<int>> edges(n+1);
    vector<int> parent(n+1);
    for (int i=0; i<n-1; ++i) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    makeUpParent(edges, parent, 1);
    for (int i=2; i<parent.size(); ++i) {
        cout << parent[i] << '\n';
    }
    return 0;
}
