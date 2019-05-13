#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N_MAX = 1e5;
const int INF = 987654321;

vector<int> edges[N_MAX+1];
vector<int> caches[N_MAX+1];
int n;

int getCost(int me, int parent, int ban) {
    if (ban >= caches[me].size()) ban = 0;
    int &cost= caches[me][ban];
    if (cost > 0) return cost;

    cost = INF;
    vector<int> &edge = edges[me];
    for (int i=1; i<=edge.size()+1; ++i) {
        if (i == ban) continue;
        int sum = i;

        for (int child : edge) {
            if (child == parent) continue;
            sum += getCost(child, me, i);

        }
        cost = min(cost, sum);
    }
    return cost;
}

void initCaches() {
    for (int i=1; i<=n; ++i) {
        caches[i] = vector<int>(edges[i].size()+2, 0);
    }
}

int main() {
    cin >> n;

    for (int i=0; i<n-1; ++i) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    initCaches();
    cout << getCost(1, 1, 0);

    return 0;
}
