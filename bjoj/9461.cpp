#include <iostream>

using namespace std;
const int N_MAX = 100;

long long int p[N_MAX+1] = {0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9};

long long int get_p(int n) {
    if (p[n] > 0) return p[n];
    else p[n] = get_p(n-1) + get_p(n-5);
    return p[n];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << get_p(n) << '\n';
    }

    return 0;
}
