#include <iostream>
#include <deque>


using namespace std;

int main() {
    deque<int> dq;
    int n;
    cin >> n;
    while(n--) {
        string s;
        cin >> s;
        if (s == "push_front") {
            int a;
            cin >> a;
            dq.push_front(a);
        } else if (s == "push_back") {
            int a;
            cin >> a;
            dq.push_back(a);
        } else if (s == "pop_front") {
            int front = -1;
            if (dq.size() > 0) {
                front = dq.front();
                dq.pop_front();
            }
            cout << front << '\n';
        } else if (s == "pop_back") {
            int back= -1;
            if (dq.size() > 0) {
                back = dq.back();
                dq.pop_back();
            }
            cout << back << '\n';
        } else if (s == "size") {
            cout << dq.size() << '\n';
        } else if (s == "empty") {
            cout << (dq.empty() ? 1 : 0) << '\n';
        } else if (s == "front") {
            int front = -1;
            if (dq.size() > 0) {
                front = dq.front();
            }
            cout << front << '\n';
        } else if (s == "back") {
            int back= -1;
            if (dq.size() > 0) {
                back = dq.back();
            }
            cout << back << '\n';
        }
    }

    return 0;
}
