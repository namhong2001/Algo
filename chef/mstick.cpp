#include <iostream>
#include <iomanip>

using namespace std;

const int NMAX = 1e5+1;

int N;
int stmin[NMAX][26];
int stmax[NMAX][26];

int rmin(int s, int e) {
    int r = e-s+1;
    int ans = stmin[s][0];
    for (int j=0; j<26; ++j) {
        if (r & (1<<j)) {
            ans = min(ans, stmin[s][j]);
            s += 1<<j;
        }
    }
    return ans;
}

int rmax(int s, int e) {
    int r = e-s+1;
    int ans = stmax[s][0];
    for (int j=0; j<26; ++j) {
        if (r & (1<<j)) {
            ans = max(ans, stmax[s][j]);
            s += 1<<j;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    int arr[N];
    for (int i=0; i<N; ++i) cin >> arr[i];
    for (int i=0; i<N; ++i) {
        stmin[i][0] = arr[i];
        stmax[i][0] = arr[i];
    }
    for (int j=1; j<26; ++j) {
        for (int i=0; i+(1<<j) <= N; ++i) {
            stmin[i][j] = min(stmin[i][j-1], stmin[i+(1<<(j-1))][j-1]);
            stmax[i][j] = max(stmax[i][j-1], stmax[i+(1<<(j-1))][j-1]);
        }
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int L, R;
        cin >> L >> R;
        int toend = rmin(L, R);
        double ans = (double)(rmax(L, R) + toend) / 2;
        int remain = -1;
        if (L != 0) {
            remain = max(remain, rmax(0, L-1));
        }
        if (R != N-1) {
            remain = max(remain, rmax(R+1, N-1));
        }
        if (remain != -1) {
            ans = max(ans, (double)toend + remain);
        }
        cout << fixed << setprecision(1) << ans << '\n';
    }
    return 0;
}