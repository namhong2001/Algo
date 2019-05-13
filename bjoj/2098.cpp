#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 987654321;
const int N_MAX = 16;
int weight[N_MAX][N_MAX];
int cache[N_MAX][1<<N_MAX];

int n;
int tsp(int here, int visited, int start) {
    if (visited == (1<<n) - 1) return weight[here][start];

    int &ret = cache[here][visited];
    if (ret != -1) return ret;

    ret = INF;
    for (int i=0; i<n; ++i) {
        if (visited & 1<<i) continue;
        ret = min(ret, tsp(i, visited | 1<<i, start) + weight[here][i]);
    }
    return ret;
}

int main() {
    cin >> n;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            cin >> weight[i][j];
            if (weight[i][j] == 0) weight[i][j] = INF;
        }
    }
    memset(cache, -1, sizeof(cache));
//    int ans = INF;
//    for (int i=0; i<n; ++i) {
//        memset(cache, -1, sizeof(cache));
//        ans = min(ans, tsp(i, 1<<i, i));
//    }
//    cout << ans;
    cout << tsp(0, 1, 0);
    return 0;
}
