#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    unordered_set<int> us;
    int n;
    cin >> n;
    for (int i=0; i<n; ++i) {
        int a;
        cin >> a;
        us.insert(a);
    }
    int m;
    cin >> m;
    for (int i=0; i<m; ++i) {
        int a;
        cin >> a;
        if (us.find(a) == us.end()) {
            cout << 0 << '\n';
        } else {
            cout << 1 << '\n';
        }
    }
    return 0;
}
