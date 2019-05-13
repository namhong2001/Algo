#include <iostream>
#include <cstring>
#include <utility>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int* prevC = new int[5];
int* nextC = new int[5];
int prevNum = 0;

int cost(int from, int to) {
    if (from == 0) return 2;
    if (from == to) return 1;
    if (abs(from-to) == 1) return 3;
    else return 4;
}

void step(int num) {
    memset(nextC, 0, sizeof(int)*5);
    nextC[prevNum] = INF;

    if (prevNum == 0) {
        nextC[prevNum] = cost(prevNum, num);
    } else {
        for (int i=0; i<5; ++i) {
            if (i == num || i == prevNum) continue;
            nextC[i] = prevC[i] + cost(prevNum, num);
        }
        for (int i=0; i<5; ++i) {
            if (i == prevNum) continue;
            nextC[prevNum] = min(nextC[prevNum], prevC[i] + cost(i, num));
        }
    }
    for (int i=0; i<5; ++i) {
        cout << nextC[i] << ' ';
    }
    cout << endl;
    prevNum = num;
    swap(prevC, nextC);
}

int main() {
    memset(prevC, 0, sizeof(int)*5);

    while (true) {
        int num;
        cin >> num;
        if (num == 0) {
            break;
        }
        step(num);
    }
    int ans = INF;
    for (int i=0; i<5; ++i) {
        if (i == prevNum) continue;
        ans = min(ans, prevC[i]);
    }
    cout << ans;

    return 0;
}
