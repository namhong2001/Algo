#include <iostream>
#include <vector>

using namespace std;


vector<int> r;

int f(int me) {
    return r[me] = r[me] == me ? me : f(r[me]);
}

void u(int a, int b) {
    a = f(a), b = f(b);
    r[a] = b;
}

int main() {
    int n, m;
    cin >> n >> m;


    vector<int> status(n);
    vector<vector<int>> switches(n);

    r.resize(m*2);
    for (int i=0; i<2*m; ++i) r[i] = i;
    for (int i=0; i<n; ++i) cin >> status[i];

    for (int i=0; i<m; ++i) {
        int k;
        cin >> k;
        for (int j=0; j<k; ++j) {
            int a;
            cin >> a;
            a--;
            switches[a].push_back(i);
        }
    }
    for (int i=0; i<n; ++i) {
        int a = switches[i][0];
        int b = switches[i][1];
        a*=2, b*=2;
        int not_a = a+1;
        int not_b = b+1;
        if (status[i] == 1) {
            u(a, b);
            u(not_a, not_b);
        } else {
            u(a, not_b);
            u(b, not_a);
        }
    }
    for (int i=0; i<2*m; i+=2) {
        if (f(i) == f(i+1)) {
            cout << 0;
            return 0;
        }
    }
    cout << 1;
    return 0;

}
