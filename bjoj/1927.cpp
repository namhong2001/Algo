#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int, vector<int>, greater<int>> min_heap;
    int n;
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        if (a > 0) {
            min_heap.push(a);
        } else if (a == 0) {
            int out = 0;
            if (!min_heap.empty()) {
                out = min_heap.top();
                min_heap.pop();
            }
            cout << out << '\n';
        }
    }
    return 0;
}
