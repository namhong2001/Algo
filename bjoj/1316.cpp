#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int ret = 0;
    while(n--) {
        int i;
        string s;
        cin >> s;
        bool flag[26] = {false};
        for (i=0; i<s.size(); ++i) {
            if (!flag[s[i] - 'a']) {
                flag[s[i] - 'a'] = true;
            } else if (flag[s[i] - 'a'] && s[i-1] != s[i]) {
                break;
            }
        }
        if (i == s.size()) {
            ++ret;
        }
    }
    cout << ret;
}
