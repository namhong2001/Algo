#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N_MAX = 100;
const int W_MAX = 1001;

int n, w;
string names[N_MAX];
int vols[N_MAX];
int prios[N_MAX];

int cache[N_MAX+1][W_MAX];
int next_idx[N_MAX+1][W_MAX];

int max_prio(int idx, int remain_weight) {
    int &ret = cache[idx+1][remain_weight];
    if (ret != -1) return ret;

    ret = 0;
    for (int i=idx+1; i<n; ++i) {
        int vol = vols[i];
        if (vol <= remain_weight) {
            int prio = prios[i];
            int candi = prio + max_prio(i, remain_weight - vol);
            if (candi > ret) {
                ret = candi;
                next_idx[idx+1][remain_weight] = i;
            }
        }
    }
    return ret;
}

vector<int> recon(int idx, int remain) {
    vector<int> ret;
    while (next_idx[idx+1][remain] != -1) {
        idx = next_idx[idx+1][remain];
        remain -= vols[idx];
        ret.push_back(idx);
    }
    return ret;
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        memset(cache, -1, sizeof(cache));
        memset(next_idx, -1, sizeof(next_idx));
        cin >> n >> w;
        for (int i=0; i<n; ++i) {
            cin >> names[i] >> vols[i] >> prios[i];
        }
        cout << max_prio(-1, w) << ' ';
        vector<int> things = recon(-1, w);
        cout << things.size() << endl;
        for (int i : things) {
            cout << names[i] << endl;
        }
    }

    return 0;
}
