#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;

typedef long long ll;
struct P {
    ll x, y, z;
};
struct E {
    ll d, a, b;
};

bool operator < (const E &a, const E &b) {
    return a.d < b.d;
}

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

vector<E> edges;

vector<int> r;
int f(int a) {
    return r[a] = r[a] == a ? a : f(r[a]);
}

void u(int a, int b) {
    a = f(a), b = f(b);
    r[a] = b;
}

int main() {
    int n;
    cin >> n;
    points.clear();
    edges.clear();
    r.resize(n);
    for (int i=0; i<n; ++i) r[i] = i;
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

    for (int p=0; p<3; ++p) {
        for (int i=0; i<n-1; ++i) {
            int a = pos[p][i].second;
            int b = pos[p][i+1].second;
            edges.push_back({dist(a,b), a, b});
        }
    }
    sort(edges.begin(), edges.end());
    ll ans = 0;
    for (E &e : edges) {
        ll d = e.d;
        ll a = e.a;
        ll b = e.b;
        if (f(a) != f(b)) {
            u(a, b);
            ans += d;
            cout << a << ' ' << b << ' ' << d << endl;
        }
    }
    cout << ans << '\n';

    return 0;
}

