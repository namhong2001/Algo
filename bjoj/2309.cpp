#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int height[9];
    int sum = 0;
    for (int i=0; i<9; ++i) {
        cin >> height[i];
        sum += height[i];
    }
    int n = sizeof(height) / sizeof(height[0]);
    sort(height, height + n);
    int faker_sum = sum - 100;
    for (int i=0; i<9; ++i) {
        for (int j=i; j<9; ++j) {
            if (height[i] + height[j] == faker_sum) {
                for (int k=0; k<9; ++k) {
                    if (k == i || k == j) continue;
                    cout << height[k] << '\n';
                }
                return 0;
            }
        }
    }

    return 0;
}
