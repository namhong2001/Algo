#include <iostream>
#include <cstring>
#include <limits>
#include <algorithm>

using namespace std;

const int N_MAX = 100;
const long long NEGINF = numeric_limits<long long>::min();
int A[N_MAX];
int B[N_MAX];
int cache[N_MAX+1][N_MAX+1];
int n, m;

int solve(int a_pos, int b_pos) {
    int &ret = cache[a_pos+1][b_pos+1];

    if (ret == -1) {
        long long a = a_pos == -1 ? NEGINF : A[a_pos];
        long long b = b_pos == -1 ? NEGINF : B[b_pos];
        long long max_elem = max(a, b);
        ret = 2;
        for (int i=a_pos+1; i<n; ++i) {
            if (A[i] > max_elem) {
                ret = max(ret, solve(i, b_pos)+1);
            }
        }
        for (int i=b_pos+1; i<m; ++i) {
            if (B[i] > max_elem) {
                ret = max(ret, solve(a_pos, i)+1);
            }
        }
    }
    return ret;
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        cin >> n >> m;
        memset(cache, -1, sizeof(cache));
        for (int i=0; i<n; ++i) {
            cin >> A[i];
        }
        for (int i=0; i<m; ++i) {
            cin >> B[i];
        }
        cout << solve(-1, -1) - 2 << endl;
    }

    return 0;
}
