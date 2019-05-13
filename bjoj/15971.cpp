#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

const int N_MAX = 100001;

vector<pair<int, int>> load[N_MAX];
vector<int> pathCost;


bool dfs (int parent, int me, int target) {
    if (me == target) return true;

    for (int i=0; i<load[me].size(); ++i) {
        auto& cur = load[me][i];
        if (cur.first == parent) continue;

        if (dfs(me, cur.first, target)) {
            pathCost.push_back(cur.second);
            return true;
        }

    }

    return false;
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    for (int i=0; i<n-1; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        load[x].push_back({y, c});
        load[y].push_back({x, c});
    }
    dfs(-1, a, b);

    int ans = 0;
    if (!pathCost.empty()) {
        sort(pathCost.begin(), pathCost.end());
        for (int i=0; i<pathCost.size()-1; ++i) {
            ans += pathCost[i];
        }
    }

    cout << ans;


    return 0;
}
