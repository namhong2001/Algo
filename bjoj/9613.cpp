#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int gcd(int a, int b) {
    if (a<b) return gcd(b, a);
    return a%b == 0 ? b : gcd(b, a%b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N; 
        ll ans = 0;
        vector<int> arr(N);
        for (int i=0; i<N; ++i) {
            cin >> arr[i];
        }
        for (int i=0; i<N; ++i) {
            for (int j=i+1; j<N; ++j) {
                ans += gcd(arr[i], arr[j]);
            }
        }
        cout << ans << '\n';
    } 
    return 0;
}

