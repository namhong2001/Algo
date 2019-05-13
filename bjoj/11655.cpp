#include <iostream>

using namespace std;

int main() {
    string str;
    getline(cin, str);
    for (int i=0; i<str.size(); ++i) {
        char my_char = str[i];
        if ((my_char >= 'a' && my_char <= 'z') || (my_char >= 'A' && my_char <= 'Z')) {
            int candidate = my_char + 13;
            if ((my_char <= 'z' && candidate > 'z') || (my_char <= 'Z' && candidate > 'Z')) {
                candidate -= 26;
            }
            str[i] = (char)candidate;
        }
    }
    cout << str;
    return 0;
}

