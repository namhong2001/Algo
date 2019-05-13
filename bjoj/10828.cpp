#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;
    stack<int> stk;
    while(n--) {
        string s;
        cin >> s;
        if (s == "push") {
            int a;
            cin >> a;
            stk.push(a);
        } else if (s == "pop") {
            if (stk.size() > 0) {
                cout << stk.top() << '\n';
                stk.pop();
            } else {
                cout << -1 << '\n';
            }
        } else if (s == "size") {
            cout << stk.size() << '\n';
        } else if (s == "empty") {
            cout << (int)stk.empty() << '\n';
        } else if (s == "top") {
            if (stk.size() > 0) {
                cout << stk.top() << '\n';
            } else {
                cout << -1 << '\n';
            }

        }
    }

    return 0;

}
