#include <iostream>

using namespace std;

int main() {
    while (true) {
        string str;
        getline(cin, str);
        if (str.empty()) break;
        int cnt_arr[4] = {0};
        for (auto my_char : str) {
            if (my_char >= 'a' && my_char <= 'z') {
                cnt_arr[0]++;
            } else if (my_char >= 'A' && my_char <= 'Z') {
                cnt_arr[1]++;
            } else if (my_char >= '0' && my_char <= '9') {
                cnt_arr[2]++;
            } else if (my_char == ' ') {
                cnt_arr[3]++;
            }
        }
        for (auto i : cnt_arr) {
            cout << i << ' ';
        }
        cout << '\n';
    }
    return 0;
}
