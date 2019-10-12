#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    int ans = 0;
    for (int i=0; i<N; ++i) {
        if (S[i] == '<') ans++;
        else break;
    }
    for (int i=N-1; i>=0; --i) {
        if (S[i] == '>') ans++;
        else break;
    }
    cout << ans;
    return 0;
}