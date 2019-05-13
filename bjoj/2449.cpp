#include <iostream>
#include <vector>


using namespace std;

const int N_MAX = 200;
const int INF = 987654321;

int cache[N_MAX][N_MAX] = {};

bool isInCommon(int A_start, int A_end, int B_start, int B_end, vector<int> &bulbs) {
    if (bulbs[A_start] == bulbs[B_start] ||
        bulbs[A_start] == bulbs[B_end] ||
        bulbs[A_end] == bulbs[B_start] ||
        bulbs[A_end] == bulbs[B_end])
    {
        return true;
    }
    return false;

}

int changeCnt(int start, int end, vector<int> &bulbs) {
    if (start == end) return 0;
    int &ret = cache[start][end];
    if (ret != 0) return ret;

    ret = INF;
    for (int i=start; i<end; ++i) {
        ret = min(ret, changeCnt(start, i, bulbs) + changeCnt(i+1, end, bulbs) + (int)(!isInCommon(start, i, i+1, end, bulbs)));
    }
    if (bulbs[start] == bulbs[end]) {
        ret = min(ret, changeCnt(start+1, end-1, bulbs)+1);
    }

    return ret;
}

int main() {
    int n, k, bulb;
    cin >> n >> k;
    int pBulb = -1;
    vector<int> bulbs;
    for (int i=0; i<n; ++i) {
        cin >> bulb;
        if (bulb != pBulb) {
            bulbs.push_back(bulb);
        }
        pBulb = bulb;
    }
    cout << changeCnt(0, bulbs.size()-1, bulbs);

    return 0;
}
