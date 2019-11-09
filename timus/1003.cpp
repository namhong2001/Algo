#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>

using namespace std;

map<int,int> r;
int f(int a) {
    return r[a] = r[a] == a ? a : f(r[a]);
}

void u(int a, int b) {
    a = f(a), b = f(b);
    r[a] = b;
}

int main() {
    while (true) {
        r.clear();
        int N, Q;
        cin >> N >> Q;
        if (N == -1) break;
        int ans = -1;
        for (int i=0; i<Q; ++i) {
            int s, e;
            string answer;
            cin >> s >> e >> answer;
            s--;
            if (r.find(2*s) == r.end()) {
                r[2*s] = 2*s;
                r[2*s+1] = 2*s+1;
            }
            if (r.find(2*e) == r.end()) {
                r[2*e] = 2*e;
                r[2*e+1] = 2*e+1;
            }
            if (answer == "odd") {
                u(2*s, 2*e+1);
                u(2*s+1, 2*e);
            } else if (answer == "even") {
                u(2*s, 2*e);
                u(2*s+1, 2*e+1);
            }
            if (f(2*s) == f(2*s+1) || f(2*e) == f(2*e+1)) {
                if (ans == -1) {
                    ans = i;
                }
            } 
        }
        if (ans != -1) {
            cout << ans << endl;
        } else {
            cout << Q << endl;
        }
    }
    return 0;
}