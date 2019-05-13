#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

const int e = 123456780;

int pow(int a, int b) {
    int ret = 1;
    while (b--) ret *=a;
    return ret;
}

int swap(int n, int pos1, int pos2) {
    int pow1 = pow(10, pos1);
    int pow2 = pow(10, pos2);
    int val1 = n/pow1 % 10;
    int val2 = n/pow2 % 10;
    return n-val1*pow1+val2*pow1-val2*pow2+val1*pow2;
}

int bfs(int s) {
    unordered_map<int, int> step;
    step[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int here = q.front();
        q.pop();
        if (here == e) return step[here];
        int zi;
        for (int i=0; i<9; ++i) {
            if (here/pow(10,i) % 10 == 0) {
                zi = i;
                break;
            }
        }
        int nexti[4];
        nexti[0] = zi%3 != 2 ? zi+1 : -1;
        nexti[1] = zi%3 != 0 ? zi-1 : -1;
        nexti[2] = zi<6 ? zi+3 : -1;
        nexti[3] = zi>2 ? zi-3 : -1;

        for (int i=0; i<4; ++i) {
            if (nexti[i] == -1) continue;
            int next = swap(here, zi, nexti[i]);
            if (step.find(next) == step.end()) {
                step[next] = step[here]+1;
                q.push(next);
            }
        }
    }
    return -1;
}

int main() {
    int s = 0;
    for (int i=0; i<9; ++i) {
        s*=10;
        int a;
        cin >> a;
        s+=a;
    }
    cout << bfs(s) << endl;
}
