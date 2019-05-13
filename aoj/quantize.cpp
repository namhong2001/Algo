#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

const int N_MAX = 100;
const int S_MAX = 10;
const int INF = 987654321;

int n, s;
int nums[N_MAX];
int cache[N_MAX][S_MAX]; //start, n
int pSum[N_MAX];
int pSqSum[N_MAX];


int getVar(int start, int end, int avg) {
    int ret = pSqSum[end] - pSqSum[start] + nums[start]*nums[start];
    ret -= 2*avg*(pSum[end]-pSum[start]+nums[start]);
    ret += avg*avg*(end-start+1);
    return ret;
}

int getMinVar(int start, int end) {
    int avg = round((pSum[end]-pSum[start]+nums[start]) / (double)(end-start+1));
    return getVar(start, end, avg);
}

int solve(int start, int sCnt) {
    if (start == n) return 0;
    if (sCnt  == 0) return INF;

    int &ret = cache[start][sCnt];
    if (ret != -1) return ret;

    else  {
        ret = INF;
        for (int i=start; i<n; ++i) {
            ret = min(ret, getMinVar(start, i) + solve(i+1, sCnt-1));
        }
    }
    return ret;
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        cin >> n >> s;
        memset(cache, -1, sizeof(cache));
        for (int i=0; i<n; ++i) {
            cin >> nums[i];
        }
        sort(nums, nums+n);
        for (int i=0; i<n; ++i) {
            pSum[i] = nums[i];
            pSqSum[i] = nums[i]*nums[i];
            if (i>0) {
                pSum[i] += pSum[i-1];
                pSqSum[i] += pSqSum[i-1];
            }
        }
        cout << solve(0, s) << endl;
    }

    return 0;
}
