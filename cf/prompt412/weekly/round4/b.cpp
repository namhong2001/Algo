#include <iostream>

using namespace std;

int main() {
    int N, P, Q;
    cin >> N >> P >> Q;
    string S;
    cin >> S;
    for (int i=0; i<=100; ++i) {
        if (N-i*P < 0) break;
        if ((N-i*P) % Q == 0) {
            cout << i + (N-i*P)/Q << '\n';
            int cnt = i;
            int s = 0;
            while (cnt--) {
                for (int j=0; j<P; ++j) {
                    cout << S[s+j];
                }
                s += P;
                cout << '\n';
            }
            cnt = (N-i*P) / Q;
            while (cnt--) {
                for (int j=0; j<Q; ++j) {
                    cout << S[s+j];
                }
                s += Q;
                cout << '\n';
            }
            return 0;
        }
    }
    cout << -1;
    return 0;
}