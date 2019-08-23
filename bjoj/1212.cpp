#include <iostream>
#include <algorithm>

using namespace std;

string toB(int num, bool padding) {
    string ret;
    while (num) { 
        ret += '0' + num%2;
        num /= 2;
    }
    if (padding) {
        while (ret.size() < 3) ret += '0';
    }
    reverse(ret.begin(), ret.end()); 
    return ret;
} 

int main() {
    string s;
    cin >> s;
    if (s == "0") {
        cout << 0;
        return 0;
    }
    for (int i=0; i<(int)s.size(); ++i) {
        char c = s[i]; 
        cout << toB(c-'0', i != 0);
    } 
    return 0;
}

