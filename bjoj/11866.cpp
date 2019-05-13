#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    queue<int> que;
    for(int i=1; i<=n; ++i) {
        que.push(i);
    }
    cout << '<';
    while(que.size() > 0) {
        for(int i=1; i<m; ++i) {
            int a = que.front();
            que.pop();
            que.push(a);
        }
        cout << que.front();
        que.pop();
        if (que.size() > 0) {
            cout << ", ";
        }
    }
    cout << '>';
    return 0;
}
