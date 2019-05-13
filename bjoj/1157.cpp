#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> r(26);

    for (auto c : s) {
        if (c >='a') {
            r[c - 'a']++;
        } else {
            r[c - 'A']++;
        }
    }
    auto i = max_element(r.begin(), r.end());
    if (count(r.begin(), r.end(), *i) > 1) {
        cout << '?';
    } else {
        cout << char(distance(r.begin(), i)+'A');
    }

    return 0;
}
