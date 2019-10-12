#include <iostream>
#include <unordered_map>

using namespace std;

typedef long long ll;

int gcd(int a, int b) {
    if (b > a) return gcd(b, a);
    return a % b == 0 ? b : gcd(b, a%b);
}

int main() {
    int N;
    cin >> N;
    unordered_map<int,ll> A, B, ans;
    while (N--) {
        int num;
        cin >> num;
        B[num]++;
        ans[num]++;
        for (auto a : A) {
            int g = gcd(a.first, num);
            B[g] += a.second;
            ans[g] += a.second;
        }
        swap(A, B);
        B.clear();
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int x;
        cin >> x;
        cout << ans[x] << '\n';
    }
    return 0;
}