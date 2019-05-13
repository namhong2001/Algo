#include <iostream>

using namespace std;

int main() {
    int t, r;
    string s;
    cin >> t;

    while(t--) {
        cin >> r >> s;

        for(auto c : s) {
            for (int i=0; i<r; ++i) {
                cout << c;
            }
        }
        cout << '\n';
    }
    return 0;
}
