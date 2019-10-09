#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int M;
    cin >> M;
    int arr[M+1];
    for (int i=1; i<=M; ++i) cin >> arr[i];
    int st[M+1][26];
    for (int i=1; i<=M; ++i) st[i][0] = arr[i];
    for (int j=1; j<=25; ++j) {
        for (int i=1; i<=M; ++i) {
            st[i][j] = st[st[i][j-1]][j-1];
        }
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int n, x;
        cin >> n >> x;
        for (int j=0; j<=25; ++j) {
            if (n & (1<<j)) {
                x = st[x][j];
            }
        }
        cout << x << '\n';
    }
    return 0;
}