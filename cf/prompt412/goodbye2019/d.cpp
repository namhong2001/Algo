#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

struct INPUT {
    int x, y, value;

    bool operator < (const INPUT &other) {
        return abs(x - y) < abs(other.x - other.y);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    vector<INPUT> input(m);
    vector<bool> check(n + 1, false);
    vector<int> ans(n + 1, 0);

    for(int i = 0; i < m; i++) {
        cin >> input[i].x >> input[i].y >> input[i].value;
    }

    sort(input.begin(), input.end());

    for(int i = 0; i < m; i++) {
        int x = input[i].value;
        if(input[i].y - input[i].x == 0) {
            check[input[i].x] = true;
            ans[input[i].x] = input[i].value;
            continue;
        }
        
        int cnt = 0;
        
        for(int j = input[i].x; j <= input[i].y; j++) {
            x ^= ans[j];
            cnt++;
        }

        
    }

    for(int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }

    return 0;
}