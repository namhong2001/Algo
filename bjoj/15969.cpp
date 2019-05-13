#include <iostream>

using namespace std;


int main() {
    int n;
    cin >> n;
    int mi = 1001, ma = -1;
    for (int i=0; i<n; ++i) {
        int c;
        cin >> c;
        if (c > ma) ma = c;
        if (c < mi) mi = c;
    }
    cout << ma - mi;


    return 0;
}
