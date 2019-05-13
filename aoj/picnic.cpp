#include <iostream>

using namespace std;

const int N_MAX = 10;

int couple(int n, bool is_friend[N_MAX][N_MAX], bool is_taken[N_MAX]) {
    int me = -1;
    for (int i=0; i<n; ++i) {
        if (is_taken[i] == false) {
            me = i;
            break;
        }
    }
    if (me == -1) return 1; // everyone coupled
    int ret = 0;
    for (int i=me+1; i<n; ++i) {
        if (is_taken[i] == false && is_friend[me][i]) {
            is_taken[me] = is_taken[i] = true;
            ret += couple(n, is_friend, is_taken);
            is_taken[me] = is_taken[i] = false;
        }
    }
    return ret;
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        int n, m;
        cin >> n >> m;
        bool is_friend[N_MAX][N_MAX] = {};
        bool is_taken[N_MAX] = {};
        for (int i=0; i<m; ++i) {
            int a, b;
            cin >> a >> b;
            is_friend[a][b] = is_friend[b][a] = true;
        }
        cout << couple(n, is_friend, is_taken) << endl;
    }


    return 0;
}
