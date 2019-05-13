#include <iostream>
#include <algorithm>

using namespace std;

const int N_MAX = 100000;
const int M_MAX = 100000;


int startCounts[N_MAX+1];
int endCounts[N_MAX+1];

int main() {
    int n, m, prevP = -1, curP;
    cin >> n >> m;

    cin >> prevP;
    for (int i=0; i<m-1; ++i) {
        int s, e;
        cin >> curP;
        if (prevP > curP) s=curP, e=prevP;
        else s=prevP, e=curP;
        startCounts[s]++;
        endCounts[e]++;

        swap(prevP, curP);
    }
    long long  railCnt = 0;
    long long ans = 0;
    for (int i=1; i<n; ++i) {
        long long a, b, c;
        cin >> a >> b >> c;
        railCnt += startCounts[i] - endCounts[i];
        long long aCost = railCnt * a;
        long long bcCost = railCnt * b + c;
        ans += min(aCost, bcCost);
    }
    cout << ans;
    return 0;
}
