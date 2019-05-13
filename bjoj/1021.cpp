#include <iostream>
#include <deque>

using namespace std;

int main() {
    deque<int> dq;
    int n, m;
    cin >> n >> m;
    for (int i=1; i<=n; ++i) {
        dq.push_back(i);
    }
    int sum = 0;
    while (m--) {
        int p;
        cin >> p;
        int cnt = 0;
        while(dq.front() != p) {
            int t = dq.front();
            dq.pop_front();
            dq.push_back(t);
            ++cnt;
        }
        if (cnt > dq.size()/2) {
            cnt = dq.size()-cnt;
        }
        sum += cnt;
        dq.pop_front();
    }
    cout << sum;


    return 0;
}
