#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int x, y;
        cin >> x >> y;
        int d = y-x;
        int m=0;
        int z=0;
        int zz=2;
        while(d>0) {
            d -= z;
            --zz;
            if (zz == 0) {
                zz = 2;
                ++z;
            }
            ++m;
            --d;
        }
        cout << m << '\n';
    }
    return 0;
}
