#include <iostream>

using namespace std;

int main() {
    string str;
    cin >> str;
    int char_count['z' - 'a' + 1] = {0};
    for (auto my_char : str) {
        char_count[my_char-'a']++;
    }
    for (auto i : char_count) {
        cout << i << ' ';
    }
    return 0;
}
