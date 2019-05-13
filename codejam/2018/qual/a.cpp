#include <iostream>
#include <queue>
#include <unordered_map>


using namespace std;

int l;
int d;

int damage(int seq) {
    int mask = 1<<(l-1);
    int ret = 0;
    int power = 1;
    while (mask) {
        if (seq & mask) {
            power<<=1;
        } else {
            ret += power;
        }
        mask>>=1;
    }
    return ret;
}

int swap(int seq, int i, int j) {
    int ival = (seq & (1<<i)) ? 1 : 0;
    int jval = (seq & (1<<j)) ? 1 : 0;
    return seq - ival*(1<<i) + jval*(1<<i) - jval*(1<<j) + ival*(1<<j);
}

int bfs(int s) {
    queue<int> q;
    unordered_map<int,int> step;
    q.push(s);
    step[s] = 0;
    while (!q.empty()) {
        int here = q.front();
        q.pop();
        if (damage(here) <= d) return step[here];
        for (int i=0; i<l-1; ++i) {
            int next = swap(here, i, i+1);
            if (step.find(next) == step.end()) {
                step[next] = step[here]+1;
                q.push(next);
            }
        }
    }
    return -1;
}

int main() {
    int T;
    cin >> T;
    for (int t=1; t<=T; ++t) {
        string p;
        cin >> d >> p;
        l = p.size();
        int s = 0;
        for (int i=0; i<p.size(); ++i) {
            s <<= 1;
            if (p[i] == 'C') s+=1;
        }
        int ans = bfs(s);
        if (ans == -1) {
            cout << "Case #" << t << ": " << "IMPOSSIBLE" << endl;
        } else {
            cout << "Case #" << t << ": " << ans << endl;
        }
    }
    return 0;
}
