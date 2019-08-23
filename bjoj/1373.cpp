#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    if (s.size()%3) { 
        string temp;
        for (int i=0; i<(3-(int)s.size()%3); ++i) { 
            temp += '0';
        }
        temp += s;
        s = temp;
    } 
    int num = 0;
    int cnt = 0;
    for (char c : s) {
        num <<= 1; 
        if (c == '1') num |= 1;
        cnt++;
        if (cnt == 3) {
            cout << num;
            cnt = 0;
            num = 0;
        }
    } 
    return 0;
}

