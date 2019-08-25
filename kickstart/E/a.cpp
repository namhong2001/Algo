#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>

using namespace std;

vector<int> r;
int f(int a) {
    return r[a] = a == r[a] ? a : f(r[a]);
}
void u(int a, int b) {
    a = f(a), b = f(b);
    r[a] = b;
}

int main() {
    int T;
    cin >> T;
    for (int t=1; t<=T; ++t) { 
        int N, M;
        cin >> N >> M;
        r.resize(N);
        iota(r.begin(), r.end(), 0);
        for (int i=0; i<M; ++i) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            u(a, b);
        }
        set<int> components;
        for (int i=0; i<N; ++i) { 
            components.insert(f(i));
        }
        int sz = components.size();
        int ans = (sz-1)*2 + (N-sz);
        cout << "Case #" << t << ": " << ans << '\n'; 
    } 
    return 0;
}

