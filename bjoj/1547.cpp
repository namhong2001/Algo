#include <iostream>

using namespace std;

int main() {
    int m;
    cin >> m;
    int ans = 1;
    while (m--) {
        int x, y;
        cin >> x >> y;
        if (x == ans) ans = y;
        else if (y == ans) ans = x;
    }
    cout << ans;

    return 0;
}
