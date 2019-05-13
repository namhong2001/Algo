#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int weight[n];
    int height[n];
    for (int i=0; i<n; ++i) {
        cin >> weight[i] >> height[i];
    }
    int ranking[n];
    for (int i=0; i<n; ++i) {
        int rank = 1;
        for (int j=0; j<n; ++j) {
            if (weight[j] > weight[i] && height[j] > height[i]) {
                rank++;
            }
        }
        ranking[i] = rank;
        cout << rank << ' ';
    }
    return 0;
}
