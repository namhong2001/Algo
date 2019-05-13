#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    int wc = 0;
    for (int i=0; i<s.size(); ++i, ++wc) {
        char c = s[i];
        char c1 = s[i+1];
        char c2 = s[i+2];
        if (c == 'c' && c1 == '=' || c1 == '-') {
            i++;
        } else if (c == 'd' && c1 == 'z' && c2 == '=') {
            i += 2;
        } else if (c == 'd' && c1 == '-') {
            i++;
        } else if (c == 'l' && c1 == 'j') {
            i++;
        } else if (c == 'n' && c1 == 'j') {
            i++;
        } else if (c == 's' && c1 == '=') {
            i++;
        } else if (c == 'z' && c1 == '=') {
            i++;
        }
    }
    cout << wc;
    return 0;
}
