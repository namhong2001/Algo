#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> rd; //reversed decimals
    int cnt = -1;
    while (cnt < n) {
        bool updated = false;
        int i;
        for (i=0; i<(int)rd.size()-1; ++i) {
            if (rd[i]+1 < rd[i+1]) {
                rd[i]++;
                updated = true;
                break;
            }
        }

        if (!updated) {
            if (!rd.empty() && rd[i] < 9) {
                rd[i]++;
            } else {
                rd.push_back(rd.size());
                i++;
            }
        }
        for (int j=0; j<i; ++j) {
            rd[j] = j;
        }
        if (rd.size() > 10) {
            cout << -1;
            return 0;
        }
        ++cnt;
    }
    for (int i=rd.size()-1; i>=0; --i) {
        cout << rd[i];
    }
    return 0;
}
