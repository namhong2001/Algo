#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int get_most(vector<int> &A, int s, int e) {
    int most = -1;
    for (int i=s; i<=e; ++i) {
        most = max(most, A[i]);
    }
    return most;
}

int main() {
    int T;
    cin >> T;
    for (int t=1; t<=T; ++t) {
        int N, K;
        cin >> N >> K;
        vector<int> C;
        vector<int> D;
        for (int i=0; i<N; ++i) {
            int c;
            cin >> c;
            C.push_back(c);
        }
        for (int i=0; i<N; ++i) {
            int d;
            cin >> d;
            D.push_back(d);
        }
        int ans = 0;
        for (int i=0; i<N; ++i) {
            for (int j=i; j<N; ++j) {
                int c_most = get_most(C, i, j);
                int d_most = get_most(D, i, j);
                if (abs(c_most-d_most) <= K) ans++;
            }
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}
