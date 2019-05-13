#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;
const int N_MAX = 5e6;
const int LEFT = -1e9;
const int RIGHT = 1e9;


int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> arr;
    for (int i=0; i<n; ++i) {
        int a;
        scanf("%d", &a);
        arr.push_back(a);
    }
    nth_element(arr.begin(), arr.begin()+k-1, arr.end());

    printf("%d", arr[k-1]);

    return 0;
}
