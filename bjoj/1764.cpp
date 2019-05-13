#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    set<string> no_hear;
    set<string> no_hear_see;

    int hear, see;
    cin >> hear >> see;
    while (hear--) {
        string name;
        cin >> name;
        no_hear.insert(name);
    }
    while (see--) {
        string name;
        cin >> name;
        if (no_hear.find(name) != no_hear.end()) {
            no_hear_see.insert(name);
        }
    }
    cout << no_hear_see.size() << '\n';
    for (auto name : no_hear_see) {
        cout << name << '\n';
    }
    return 0;
}
