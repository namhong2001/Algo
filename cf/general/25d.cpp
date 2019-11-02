#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

typedef pair<int,int> pii;

int N;
vector<int> r;
int f(int a) {
    return r[a] = r[a] == a ? a : f(r[a]);
}

void u(int a, int b) {
    a = f(a), b = f(b);
    r[a] = b;
}

int main() {
    cin >> N;
    r.resize(N+1);
    iota(r.begin(), r.end(), 0);
    vector<pii> destroy, build;
    for (int i=1; i<=N-1; ++i) {
        int a, b;
        cin >> a >> b;
        if (f(a) == f(b)) destroy.emplace_back(a, b);
        else u(a, b);
    }
    for (int i=1; i<N; ++i) {
        if (f(i) != f(i+1)) {
            u(i, i+1);
            build.emplace_back(i, i+1);
        }
    }
    cout << destroy.size() << '\n'; // destroy, build must be same size
    while (!destroy.empty()) {
        cout << destroy.back().first << ' ' << destroy.back().second << ' ' << build.back().first << ' ' << build.back().second << '\n';
        destroy.pop_back();
        build.pop_back();
    }
    return 0;
}