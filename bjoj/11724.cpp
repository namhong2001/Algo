#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <numeric> 

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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
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
    cout << components.size() << endl; 
    return 0;
}

