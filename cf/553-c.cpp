#include <iostream>
#include <vector>


using namespace std;


vector<int> root;

int f(int here) {
    if (root[here] == here) return here;
    return root[here] = f(root[here]);
}

void u(int a, int b) {
    a = f(a), b = f(b);
    root[a] = b;
}

int main() {
    int n, m;
    cin >> n >> m;
    root = vector<int>(2*n);
    for (int i=0; i<2*n; ++i) root[i] = i;

    for (int i=0; i<m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        a = a*2, b = b*2;
        int not_a = a+1;
        int not_b = b+1;

        if (c == 1) {
            u(a, b);
            u(not_a, not_b);
        } else {
            u(a, not_b);
            u(not_a, b);
        }
    }

    for (int i=0; i<2*n; i+=2) {
        if (f(i) == f(i+1)) {
            cout << 0 << endl;
            return 0;
        }
    }
    int component_cnt = 0;
    for (int i=0; i<2*n; ++i) {
        if (f(i) == i) component_cnt++;
    }
    component_cnt /= 2;
    int ans = 1;
    for (int i=0; i<component_cnt-1; ++i) {
        ans *= 2;
        ans %= 1000000007;
    }
    cout << ans << endl;
    return 0;

}
