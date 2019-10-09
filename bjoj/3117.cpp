#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, K, M;
    cin >> N >> K >> M;
    int arr[N+1];
    for (int i=1; i<=N; ++i) cin >> arr[i];
    int st[K+1][32];
    for (int i=1; i<=K; ++i) cin >> st[i][0];
    for (int j=1; j<32; ++j) {
        for (int i=1; i<=K; ++i) {
            st[i][j] = st[st[i][j-1]][j-1];
        }
    }
    M--;
    for (int i=1; i<=N; ++i) {
        int x = arr[i];
        for (int j=0; j<32; ++j) {
            if (M & (1<<j)) {
                x = st[x][j];
            }
        }
        cout << x << '\n';
    }
    return 0;
}