#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    int t = 0;
    int a[26] = {
        3,3,3,
        4,4,4,
        5,5,5,
        6,6,6,
        7,7,7,
        8,8,8,8,
        9,9,9,
        10,10,10,10
    };
    for (auto c : s) {
        t += a[c-'A'];
    }
    cout << t;
    return 0;
}
