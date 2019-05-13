#include <iostream>

using namespace std;

int main() {
    int n, x, a;
    cin >> n >> x;
    while(n--) {
        cin >> a;
        if (a < x) {
            cout << a << ' ';
        }

    }
    return 0;
}
