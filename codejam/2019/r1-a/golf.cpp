#include <iostream>
#include <vector>

using namespace std;

vector<int> primes = {16, 9, 5, 7, 11, 13, 17};

int main() {
    int T, N, M;
    cin >> T >> N >> M;
    for (int t=1; t<=T; ++t) {
        vector<int> remains(18);
        for (int i=0; i<7; ++i) {
            for (int j=0; j<18; ++j) {
                cout << primes[i] << ' ';
            }
            cout << endl;
            int tr = 0;
            for (int j=0; j<18; ++j) {
                int a;
                cin >> a;
                tr += a;
            }
            remains[i] = tr % primes[i];
        }
        for (int i=1; i<=1e6; ++i) {
            bool is_ans = true;
            for (int j=0; j<7; ++j) {
                if (i % primes[j] != remains[j]) {
                    is_ans = false;
                    break;
                }
            }
            if (is_ans) {
                cout << i << endl;
                break;
            }
        }
        int result;
        cin >> result;
        if (result == -1) return 0;
    }
    return 0;
}
