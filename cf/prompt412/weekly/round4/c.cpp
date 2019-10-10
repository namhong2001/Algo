#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    N *= 2;
    vector<int> arr(N);
    for (int i=0; i<N; ++i) cin >> arr[i];
    int ans = 0;
    for (int i=0; i<N; i+=2) {
        if (arr[i] == arr[i+1]) continue;
        for (int j=i+2; j<N; ++j) {
            if (arr[i] == arr[j]) {
                ans += j-i-1;
                arr.erase(arr.begin()+j);
                arr.insert(arr.begin()+i+1, arr[i]);
                break;
            }
        }
    }
    cout << ans;
    return 0;
}