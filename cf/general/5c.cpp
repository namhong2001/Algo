#include <iostream>
#include <map>
#include <stack>
#include <vector>

using namespace std;

int main() {
    string S;
    cin >> S;
    int ssize = S.size();
    vector<int> match(ssize, -1);
    stack<int> st;
    for (int i=0; i<ssize; ++i) {
        if (S[i] == '(') st.push(i);
        else {
            if (!st.empty()) {
                match[st.top()] = i;
                st.pop();
            }
        }
    }
    int maxlen = 0;
    int maxlencnt = 0;
    int cnt = 0;
    for (int i=0; i<ssize; ++i) {
        while (i<ssize && match[i] != -1) {
            cnt += match[i] - i + 1;
            i = match[i]+1;
        }
        if (cnt > maxlen) {
            maxlen = cnt;
            maxlencnt = 1;
        } else if (cnt == maxlen) {
            maxlencnt++;
        }
        cnt = 0;
    }
    if (maxlen == 0) {
        cout << 0 << ' ' << 1;
    } else {
        cout << maxlen << ' ' << maxlencnt;
    }
    return 0;
}