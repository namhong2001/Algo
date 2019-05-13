#include <iostream>
#include <unordered_set>

using namespace std;
const int N_MAX = 1e6+1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_set<int>* set_arr[N_MAX] = {};
    int n, m;
    cin >> n >> m;
    while (m--) {
        int action, a, b;
        cin >> action >> a >> b;
        if (action == 0) {
            if (a == b) continue;
            if (set_arr[a] == nullptr && set_arr[b] == nullptr) {
                unordered_set<int>* new_set = new unordered_set<int>();
                new_set->insert(a);
                new_set->insert(b);
                set_arr[a] = set_arr[b] = new_set;

            } else if (set_arr[a] != nullptr && set_arr[b] != nullptr) {
                unordered_set<int>* a_set = set_arr[a];
                unordered_set<int>* b_set = set_arr[b];
                if (a_set->size() > b_set->size()) {
                    for (auto i : *b_set) {
                        a_set->insert(i);
                        set_arr[i] = a_set;
                    }
                    delete b_set;
                } else  {
                    for (auto i : *a_set) {
                        b_set->insert(i);
                        set_arr[i] = b_set;
                    }
                    delete a_set;
                }
            } else {
                if (set_arr[a] == nullptr) {
                    set_arr[a] = set_arr[b];
                    set_arr[a]->insert(a);
                } else {
                    set_arr[b] = set_arr[a];
                    set_arr[b]->insert(b);
                }
            }
        } else {
            if (a == b || (set_arr[a] != nullptr && set_arr[b] != nullptr && set_arr[a] == set_arr[b])) {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
        }
    }


    return 0;
}
