#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

vector<int> r, eat;
int f(int a) {
    return r[a] = r[a] == a ? a : f(r[a]);
}

int u(int a, int b) { 
    a = f(a), b = f(b);
    if (a > b) return u(b, a);
    r[a] = b;
    return b;
}


int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        r.resize(N+4);
        eat.resize(N+4);
        iota(r.begin(), r.end(), 0);
        iota(eat.begin(), eat.end(), 0);
        int cnt = 0;
        for (int i=0; i<K; ++i) {
            int a, x, y;
            cin >> a >> x >> y;
            if (x > N || y > N) { cnt++; continue; }
            if (a == 1) {
                int rx = f(x);
                int ry = f(y);
                if (eat[rx] != rx)
                if (rx > N && ry > N && rx != ry) {cnt++; continue; }
                u(x, y);
            } else {
                if (x == y) { cnt++; continue; }
                int rx = f(x);
                int ry = f(y);
                if (rx > N && ry > N && rx%3 != (ry-1)%3) { cnt++; continue; }
                if (ry)
                

            }
        }
    }

}