#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


int get_perm(int a) {
    int ret = 1;
    for (int i=1; i<=a; ++i) ret *= i;
    return ret;
}

void fill_rest(vector<char> &ans) {
    vector<bool> has(5, false);
    for (int i=0; i<ans.size(); ++i) {
        has[ans[i]-'A'] = true;
    }
    for (int i=0; i<5; ++i) {
        if (!has[i]) ans.push_back('A'+i);
    }
}
bool contain(vector<char> &arr, char target) {
    for (int i=0; i<arr.size(); ++i) {
        if (arr[i] == target) return true;
    }
    return false;
}

int main() {
    int T, F;
    cin >> T >> F;
    for (int t=1; t<=T; ++t) {
        vector<char> ans;
        vector<int> starts;
        for (int i=0; i<119; ++i) {
            starts.push_back(1+5*i);
        }
        for (int ith=0; ith<4; ++ith) {
            vector<int> cache[5]; // by A, B, C, D, E
            for (int i=0; i<starts.size(); ++i) {
                cout << starts[i] + ith << endl;
                string resp;
                cin >> resp;
                cache[resp[0]-'A'].push_back(starts[i]);
            }

            int target_size = get_perm(4-ith)-1;
            for (int i=0; i<5; ++i) {
                if (contain(ans, 'A'+i)) continue;
                if (cache[i].size() == target_size) {
                    swap(starts, cache[i]);
                    ans.push_back('A'+i);
                    break;
                }
            }
        }
        fill_rest(ans);
        cout << string(ans.begin(), ans.end()) << endl;
        string verdict;
        cin >> verdict;
        assert(verdict == "Y");
    }
    return 0;
}
