#include <iostream>
#include <vector>


using namespace std;

int main() {
    vector<int> layer_arr;
    int n;
    cin >> n;
    for (int layer=1; layer<=n; ++layer) {
        for (int i=layer-1; i>=0; --i) {
            int num;
            cin >> num;
            int left = 0;
            int right = 0;
            if (i > 0) left = layer_arr[i-1];
            if (i < layer_arr.size()) right = layer_arr[i];
            num += max(left, right);
            if (i == layer_arr.size()) layer_arr.push_back(num);
            else layer_arr[i] = num;
        }
    }
    int max_total = 0;
    for (auto total : layer_arr) {
        if (total > max_total) max_total = total;
    }
    cout << max_total;
    return 0;
}
