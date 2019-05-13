#include <iostream>
#include <vector>
#include <utility>

using namespace std;

const int N_MAX = 1e5;
vector<pair<int, int>> edges[N_MAX+1];

int deepestNode, maxHeight;

void dfs(int me, int parent, int height) {
    if (height > maxHeight) {
        maxHeight = height;
        deepestNode = me;
    }

    for (auto child : edges[me]) {
        if (child.first == parent) continue;
        dfs(child.first, me, height+child.second);
    }
}

int main() {
    int v;
    cin >> v;
    for (int i=0; i<v; ++i) {
        int me;
        cin >> me;
        while (true) {
            int neighbor;
            cin >> neighbor;
            if (neighbor == -1) break;

            int weight;
            cin >> weight;
            edges[me].push_back({neighbor, weight});
        }
    }
    dfs(1, 1, 0);
    dfs(deepestNode, deepestNode, 0);
    cout << maxHeight;

    return 0;
}
