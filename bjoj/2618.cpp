#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;

const int INF = 987654321;
const int N_MAX = 1000;
const int W_MAX = 1000;
int n, w;
int cache[W_MAX+1][W_MAX+1];
int pos[N_MAX+2][2];
int d[W_MAX+1][W_MAX+1];


int dist(int a, int b) {
    int &ret = d[a+1][b+1];
    if (ret != -1) return ret;

    int* posA = pos[a+2];
    int* posB = pos[b+2];

    if (a < 0) posA = pos[0];
    if (b < 0) posB = pos[1];

    ret = abs(posA[0] - posB[0]) + abs(posA[1] - posB[1]);
    return ret;
}

int travel(int car1, int car2) {
    if (car1 == w-1 || car2 == w-1) return 0;

    int &ret = cache[car1+1][car2+1];
    if (ret != -1) return ret;

    ret = 0;
    int maxPos = max(car1, car2);
    if (maxPos+1 < w) {
        ret = min(travel(car1, maxPos+1) + dist(maxPos+1, car2), travel(maxPos+1, car2) + dist(car1, maxPos+1));
    }
    return ret;
}

void recon(int car1, int car2, vector<int>& record) {
    int maxPos = max(car1, car2);
    if (maxPos == w-1) return;
    if (travel(maxPos+1, car2) + dist(car1, maxPos+1) < travel(car1, maxPos+1) + dist(maxPos+1, car2)) {
        record.push_back(1);
        recon(maxPos+1, car2, record);
    } else {
        record.push_back(2);
        recon(car1, maxPos+1, record);
    }
}


int main() {
    cin >> n >> w;
    pos[0][0] = 1;
    pos[0][1] = 1;
    pos[1][0] = n;
    pos[1][1] = n;
    for (int i=0; i<w; ++i) {
        cin >> pos[i+2][0] >> pos[i+2][1];
    }
    memset(cache, -1, sizeof(cache));
    memset(d, -1, sizeof(d));

    int ans = travel(-1, -1);
    vector<int> track;
    recon(-1, -1, track);
    cout << ans << endl;
    for (int i : track) {
        cout << i << endl;
    }

    return 0;
}
