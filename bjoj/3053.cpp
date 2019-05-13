#include <iostream>
#include <iomanip>

using namespace std;

const long double pi = 3.141592653589793238462643383279502884L;

int main() {
    int r;
    cin >> r;
    cout << fixed << setprecision(6) << r*r*pi << '\n';
    cout << (double)r*r*2;
    return 0;
}
