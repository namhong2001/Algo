#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    int score[n][n];
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            cin >> score[i][j];
        }
    }
    int choose[n] = {};
    for (int i=n/2; i<n; ++i) {
        choose[i] = 1;
    }

    int ans = 987654321;
    do {
        int a_score = 0;
        int b_score = 0;
        vector<int> a_list;
        vector<int> b_list;
        for (int i=0; i<n; ++i) {
            if (choose[i] == 0) {
                a_list.push_back(i);
            } else {
                b_list.push_back(i);
            }
        }
        for (int i=0; i<a_list.size(); ++i) {
            for (int j=0; j<a_list.size(); ++j) {
                int x = a_list[i];
                int y = a_list[j];
                if (x != y) a_score += score[x][y];
            }
        }

        for (int i=0; i<b_list.size(); ++i) {
            for (int j=0; j<b_list.size(); ++j) {
                int x = b_list[i];
                int y = b_list[j];
                if (x != y) b_score += score[x][y];
            }
        }
        ans = min(ans, abs(a_score - b_score));
    } while (next_permutation(choose, choose+n));

    cout << ans;
    return 0;
}
