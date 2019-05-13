#include <iostream>
#include <queue>


using namespace std;

int main() {
    int n;
    cin >> n;
    queue<int> que;
    while(n--) {
        string s;
        cin >> s;
        if (s == "push") {
            int a;
            cin >> a;
            que.push(a);
        } else if (s == "pop") {
            int out = -1;
            if (que.size() > 0) {
                out = que.front();
                que.pop();
            }
            cout << out << '\n';
        } else if (s == "size") {
            cout << que.size() << '\n';
        } else if (s == "empty") {
            cout << (int)que.empty() << '\n';
        } else if (s == "front") {
            int out = -1;
            if (que.size() > 0) {
                out = que.front();
            }
            cout << out << '\n';
        } else if (s == "back") {
            int out = -1;
            if (que.size() > 0) {
                out = que.back();
            }
            cout << out << '\n';
        }
    }

    return 0;
}
