#include <iostream>

using namespace std;

int main() {
    int x;
    cin >> x;
    int stick = 64;
    int cnt = 1;
    while (stick != x) {
        stick /= 2;
        if (x > stick) {
            x -= stick;
            ++cnt;
        }
    }
    cout << cnt;
    return 0;
}
