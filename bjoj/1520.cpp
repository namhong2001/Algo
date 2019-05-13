#include <iostream>
#include <vector>


using namespace std;

const int HEIGHT_MAX = 10000;

vector<vector<int>> height;
vector<vector<int>> dp;

int cases(int row, int col) {
    if (row == 1 && col == 1) return 1;
    if (row == 0 || row == height.size()-1 || col == 0 || col == height[0].size()-1) return 0;
    if (dp[row][col] >= 0) return dp[row][col];

    int my_case = 0;
    int my_height = height[row][col];
    int top = height[row-1][col];
    int left = height[row][col-1];
    int right = height[row][col+1];
    int bottom = height[row+1][col];
    if (top > my_height) my_case +=  cases(row-1, col);
    if (left > my_height) my_case +=  cases(row, col-1);
    if (right > my_height) my_case +=  cases(row, col+1);
    if (bottom > my_height) my_case +=  cases(row+1, col);

    dp[row][col] = my_case;
    return my_case;
}

int main() {
    int m, n;
    cin >> m >> n;

    // init
    vector<int> top_padding(n+2, HEIGHT_MAX);
    height.push_back(top_padding);
    for (int i=0; i<m; ++i) {
        vector<int> row;
        row.push_back(HEIGHT_MAX);
        for (int j=0; j<n; ++j) {
            int a;
            cin >> a;
            row.push_back(a);
        }
        row.push_back(HEIGHT_MAX);
        height.push_back(row);
    }
    vector<int> bottom_padding(n+2, HEIGHT_MAX);
    height.push_back(bottom_padding);
    for (int i=0; i<m+2; ++i) {
        vector<int> dp_row(n+2, -1);
        dp.push_back(dp_row);
    }

    cout << cases(m, n);
    return 0;
}
