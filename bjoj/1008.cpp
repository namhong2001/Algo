#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    long double x, y;
    cin >> x >> y;
    x *= 1e10;
    cout << fixed << setprecision(10) << x/y/1e10;
    return 0;
}
