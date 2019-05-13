#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N_MAX = 100;

int pathLen[N_MAX][N_MAX];
int pathCnt[N_MAX][N_MAX];
int tri[N_MAX][N_MAX];
int n;


int maxPathLen(int a, int b) {
    if (a == n) return 0;
    int &ret = pathLen[a][b];
    if (ret != -1) return ret;

    ret = max(maxPathLen(a+1, b), maxPathLen(a+1, b+1)) + tri[a][b];
    return ret;
}

int maxPathCnt(int a, int b) {
    if (a == n-1) return 1;

    int &ret = pathCnt[a][b];

    if (ret != -1) return ret;

    int leftLen = maxPathLen(a+1, b);
    int rightLen = maxPathLen(a+1, b+1);
    int leftCnt = maxPathCnt(a+1, b);
    int rightCnt = maxPathCnt(a+1, b+1);

    if (leftLen > rightLen) {
        ret = leftCnt;
    } else if (rightLen > leftLen) {
        ret = rightCnt;
    } else {
        ret = leftCnt + rightCnt;
    }
    return ret;
}

int main() {
    int c;
    cin >> c;
    while(c--) {
        cin >> n;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<=i; ++j) {
                cin >> tri[i][j];
            }
        }
        memset(pathLen, -1, sizeof(pathLen));
        memset(pathCnt, -1, sizeof(pathCnt));
        cout << maxPathCnt(0, 0) << endl;
    }
    return 0;
}
