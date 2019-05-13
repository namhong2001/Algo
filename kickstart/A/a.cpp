#include <iostream>

using namespace std;

void solve(int a, int b, int n) {
    int q = (a+b)/2;
    cout << q << endl;
    string resp;
    cin >> resp;
    if (resp == "CORRECT") {
        return;
    } else if (resp == "TOO_SMALL") {
        solve(q+1, b, n-1);
    } else if (resp == "TOO_BIG") {
        solve(a, q-1, n-1);
    } else if (resp == "WRONG_ANSWER") {
        return;
    }

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, n;
        cin >> a >> b >> n;
        solve(a+1, b, n);
    }
    return 0;
}
