#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int h, w;
        cin >> h >> w;
        for (int i=0; i<h; ++i) {
            vector<char> row;
            for (int j=0; j<w; ++j) {
                char a;
                cin >> a;
                row.push_back(a);
            }
            reverse(row.begin(), row.end());
            for (char c : row) {
                cout << c;
            }
            cout << endl;
        }
    }

    return 0;
}
