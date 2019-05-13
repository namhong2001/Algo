#include <iostream>
#include <algorithm>

using namespace std;

const int N_MAX = 100001;

int pSum[N_MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i=1; i<=n; ++i) {
        cin >> pSum[i];
        pSum[i] += pSum[i-1];
    }
    for (int i=0; i<m; ++i) {
        int a, b;
        cin >> a >> b;
        cout << pSum[max(a,b)] - pSum[min(a, b)-1] << '\n';
    }
    return 0;
}
