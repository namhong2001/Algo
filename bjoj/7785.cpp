#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    set<string, greater<string>> company;
    int n;
    cin >> n;
    while(n--) {
        string name;
        string action;
        cin >> name >> action;
        if (action == "enter") {
            company.insert(name);
        } else {
            company.erase(name);
        }
    }
    for (auto name : company) {
        cout << name << '\n';
    }
    return 0;
}
