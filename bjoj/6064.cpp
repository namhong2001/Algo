#include <iostream>

using namespace std;

int gcd(int x, int y) {
    return x%y ? gcd(y, x%y) : y;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int m, n, x, y;
        cin >> m >> n >> x >> y;
        int lcm = m*n/(m>n?gcd(m,n):gcd(n,m));
        for(int i=0, sum=0; ; ++i) {
            sum = m*i+x;
            if (!((sum-y)%n)) {
                cout << sum << endl;
                break;
            } else if (sum > lcm) {
                cout << -1 << endl;
                break;
            }
        }

    }
    return 0;
}
