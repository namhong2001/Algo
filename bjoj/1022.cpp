#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    vector<vector<int>> spiral;
    int max_decimal = 0;
    for (int i=r1; i<=r2; ++i) {
        vector<int> row;
        for (int j=c1; j<=c2; ++j) {
            int num;
            if (i <= -1*j) {
                int pivot = pow(max(abs(i), abs(j))*2, 2) + 1;
                if (j >= i) {
                    num = pivot - (j - i);
                } else {
                    num = pivot + (i - j);
                }
            } else {
                int pivot = pow(max(abs(i), abs(j))*2+1, 2);
                int prev_pivot = pow((max(abs(i), abs(j))-1)*2+1, 2);
                if (j <= i) {
                    num = pivot - (i - j);
                } else {
                    num = prev_pivot + (j - i);
                }
            }
            max_decimal = max(max_decimal, (int)to_string(num).size());
            row.push_back(num);
        }
        spiral.push_back(row);
    }
    for (auto row : spiral) {
        for (auto num : row) {
            cout << setw(max_decimal) << num << ' ';
        }
        cout << '\n';
    }


    return 0;
}
