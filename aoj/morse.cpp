#include <iostream>
#include <limits>
#include <cstring>

using namespace std;

const int N_MAX = 100;
const long long INF = numeric_limits<long long>::max()/2;


long long cache[N_MAX+N_MAX+1][N_MAX+1];


long long getComb(int a, int b) {
    if (a == b || b == 0) return 1;

    long long &ret = cache[a][b];
    if (ret != -1) return ret;

    ret = getComb(a-1, b-1) + getComb(a-1, b);

    if (ret > INF) ret = INF;

    return ret;
}

void print_kth(int n, int m, int k) {
    if (n == 0 && m == 0) return;

    long long bound = getComb(n+m-1, n-1);
    char p;
    if (k <= bound && n > 0) {
        p = '-';
        n--;
    } else {
        p = 'o';
        m--;
        k -= bound;
    }
    cout << p;
    print_kth(n, m, k);
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        int n, m, k;
        cin >> n >> m >> k;
        memset(cache, -1, sizeof(cache));
        print_kth(n, m, k);
        cout << endl;
    }

    return 0;
}
