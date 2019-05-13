#include <iostream>

using namespace std;

int damage(string &seq) {
    int ret = 0;
    int power = 1;
    for (auto a : seq) {
        if (a == 'C') power*=2;
        else ret += power;
    }
    return ret;
}

int main() {
    int T;
    cin >> T;
    for (int t=1; t<=T; ++t) {
        int d;
        string p;
        cin >> d >> p;
        int cnt = 0;
        while (damage(p) > d) {
            bool has_next = false;
            for (int i=p.size()-1; i>0; --i) {
                if (p[i] == 'S' && p[i-1] == 'C') {
                    has_next = true;
                    swap(p[i], p[i-1]);
                    cnt++;
                    break;
                }
            }
            if (!has_next) {
                cnt = -1;
                break;
            }
        }


        if (cnt == -1) {
            cout << "Case #" << t << ": " << "IMPOSSIBLE" << endl;
        } else {
            cout << "Case #" << t << ": " << cnt << endl;
        }
    }
    return 0;


}
