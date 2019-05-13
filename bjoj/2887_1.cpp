#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>


using namespace std;
typedef long long ll;

const ll INF = 987654321987654321;

struct P {
    ll x, y, z;
};

vector<P> points;

ll dist(int a, int b) {
    ll x1 = points[a].x;
    ll y1 = points[a].y;
    ll z1 = points[a].z;

    ll x2 = points[b].x;
    ll y2 = points[b].y;
    ll z2 = points[b].z;
    return min({abs(x1 - x2), abs(y1 - y2), abs(z1 - z2)});
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    points.clear();
    vector<pair<ll,int>> pos[3];
    for (int i=0; i<n; ++i) {
        ll x, y, z;
        cin >> x >> y >> z;
        points.push_back({x, y, z});
        ll arr[3] = {x, y, z};
        for (int j=0; j<3; ++j) {
            pos[j].push_back({arr[j], i});
        }
    }
    for (int i=0; i<3; ++i) {
        sort(pos[i].begin(), pos[i].end());
    }
    vector<vector<pair<int,ll>>> adj(n);
    for (int i=0; i<3; ++i) {
        for (int j=0; j<n-1; ++j) {
            int a = pos[i][j].second, b = pos[i][j+1].second;
            ll d = dist(a, b);
            adj[a].push_back({b, d});
            adj[b].push_back({a, d});
        }
    }
    vector<bool> added(n, false);
    ll ans = 0;
    priority_queue<pair<ll, int>> pq;
    pq.push({0, 0});
    while (!pq.empty()) {
        ll d = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if (added[here]) continue;
        ans += d;
        added[here] = true;
        for (pair<int,ll> &t : adj[here]) {
            int there = t.first;
            ll w = t.second;
            if (!added[there]) {
                pq.push({-w, there});
            }
        }
    }
    cout << ans << '\n';

    return 0;
}

