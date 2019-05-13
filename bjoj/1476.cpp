#include <iostream>
#include <vector>

using namespace std;

int crt(vector<int> &moduli, vector<int> &residue) {
    int N = 1;
    for (int m : moduli) {
        N*=m;
    }
    vector<int> ss;
    for (int i=0; i<moduli.size(); ++i) {
        for (int s=0; ; ++s) {
            if (N/moduli[i]*s % moduli[i] == 1) {
                ss.push_back(s);
                break;
            }
        }
    }
    int ret = 0;
    for (int i=0; i<moduli.size(); ++i) {
        ret += residue[i]*N/moduli[i]*ss[i];
    }
    return ret % N;
}

int main() {
    vector<int> m = {15, 28, 19};
    vector<int> r;
    for (int i=0; i<3; ++i) {
        int a;
        cin >> a;
        a--;
        r.push_back(a);
    }
    cout << crt(m, r)+1 << endl;

    return 0;
}
