#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b>a) swap(a,b);
    return a%b ? gcd(b, a%b) : b;
}

int main() {
    int n, first;
    cin >> n;
    cin >> first;
    while (--n) {
        int a;
        cin >> a;
        int g = gcd(a, first);
        cout << first/g << '/' << a/g << '\n';
    }
    return 0;
}
