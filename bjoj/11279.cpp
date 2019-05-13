#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int> max_heap;
    int n;
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        if (a > 0) {
            max_heap.push(a);
        } else if (a == 0) {
            int out = 0;
            if (!max_heap.empty()) {
                out = max_heap.top();
                max_heap.pop();
            }
            cout << out << '\n';
        }
    }
    return 0;
}
