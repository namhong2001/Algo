#include <iostream>

using namespace std;

int letter_cnt[26];
bool is_forward = true;
int last_n = 0;
int pos = -1;

void proceed(int n) {
    int cycle = (n-last_n)/26;
    int step_cnt = (n-last_n)%26;

    if (cycle > 0) {
        for (int i=0; i<26; ++i) {
            letter_cnt[i] += cycle;
        }
    }
    while (step_cnt--) {
        pos += is_forward ? 1 : -1;
        if (pos < 0) pos += 26;
        else if (pos >= 26) pos -=26;
        letter_cnt[pos]++;
    }

    last_n = n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        if (s == "UPIT") {
            int n;
            string x;
            cin >> n >> x;
            proceed(n);
            cout << letter_cnt[x[0]-'a'] << '\n';
        } else if (s == "SMJER") {
            int n;
            cin >> n;
            proceed(n);
            is_forward = !is_forward;
        }
    }

    return 0;
}
