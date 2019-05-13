#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> arr[51];
    while(n--) {
        string s;
        cin >> s;
        arr[s.size()].push_back(s);
    }
    for (int i=1; i<51; ++i) {
        sort(arr[i].begin(), arr[i].end());
        for (int k=0; k<arr[i].size(); ++k) {
            if (k>0 && arr[i][k-1] == arr[i][k]) {
                continue;
            } else {
                cout << arr[i][k] << '\n';
            }
        }
    }
    return 0;
}
