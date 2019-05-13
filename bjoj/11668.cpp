#include <iostream>
#include <vector>
#include <utility>


using namespace std;

typedef pair<int,int> pii ;

vector<int> r(2010);
vector<vector<pii>> pipes(1010);
vector<pii> w_source(1010);

int f(int me) {
    return r[me] = r[me] == me ? me : f(r[me]);
}

int u(int a, int b) {
    a = f(a), b = f(b);
    r[a] = b;
}

int ccw(pii a, pii b, pii c) {
    int cp = a.first*b.second+b.first*c.second+c.first*a.second;
    cp -= a.second*b.first+b.second*c.first+c.second*a.first;
    if (cp > 0) return 1;
    if (cp < 0 ) return -1;
    return 0;
}

bool intersect(int p1, int p2) {
    pii a = pipes[p1][0];
    pii b = pipes[p1][1];
    pii c = pipes[p2][0];
    pii d = pipes[p2][1];

    if (a == c) return false;

    int ab = ccw(a, b, c) * ccw(a, b, d);
    int cd = ccw(c, d, a) * ccw(c, d, b);
    return ab <= 0 && cd <= 0;
}

int main() {
    int w, p;
    cin >> w >> p;
    for (int i=0; i<2*p; ++i) r[i] = i;
    for (int i=0; i<w; ++i) {
        int x, y;
        cin >> x >> y;
        w_source[i] = {x, y};
    }
    for (int i=0; i<p; ++i) {
        int s, x, y;
        cin >> s >> x >> y;
        s--;
        pipes[i] = {w_source[s], {x, y}};
    }
    for (int i=0; i<p; ++i) {
        for (int j=i+1; j<p; ++j) {
            if (intersect(i, j)) {
                int a = i*2;
                int b = j*2;
                u(a, b+1);
                u(a+1, b);
            }
        }
    }
    for (int i=0; i<2*p; i+=2) {
        if (f(i) == f(i+1)) {
            cout << "impossible" << endl;
            return 0;
        }
    }
    cout << "possible" << endl;
    return 0;
}
