#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int stk = 0;
        string out = "YES";
        for (auto i : s) {
            if (i == '(') {
                ++stk;
            } else {
                --stk;
            }
            if (stk < 0) {
                out = "NO";
            }
        }
        if (stk != 0) {
            out = "NO";
        }
        cout << out << '\n';
    }

    return 0;
}
