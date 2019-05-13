#include <iostream>
#include <vector>

using namespace std;


int l;
vector<int> r;

int f(int me) {
    return r[me] = r[me] == me ? me : f(r[me]);
}

void u(int a, int b) {
    a = f(a), b = f(b);
    r[a] = b;
}

int solve() {
    for (int i=0; i<l; i+=2) {
        if (f(i) == f(i+1)) return 0;
    }
    return 1;
}

int main() {
    int n, m;
    cin >> n >> m;
    l = (n+m)*2;
    r.resize(l);
    for (int i=0; i<l; ++i) r[i] = i;

    for (int i=0; i<n; ++i) {
        string s;
        cin >> s;
        for (int j=0; j<m; ++j) {
            int a = i*2;
            int not_a = a+1;
            int b = (n+j)*2;
            int not_b = b+1;
            if (s[j] == '#') {
                u(a, b);
                u(not_a, not_b);
            } else if (s[j] == '*') {
                u(a, not_b);
                u(b, not_a);
            }
        }
    }
    cout << solve() << endl;
    return 0;
}
