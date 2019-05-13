#include <iostream>
#include <cmath>

using namespace std;

string wheel[4];

void rotate(int nth, int direction) {
    string s;
    if (direction == 1) {
        s = wheel[nth].back() + wheel[nth].substr(0, wheel[nth].size()-1);
    } else if (direction == -1) {
        s = wheel[nth].substr(1) + wheel[nth].front();
    }
    wheel[nth] = s;
}

void rotate_all(int nth, int direction) {
    bool will_rotate[4] = {};
    will_rotate[nth] = true;

    for (int i=nth+1; i<4; ++i) {
        if (wheel[i-1][2] != wheel[i][6]) will_rotate[i] = true;
        else break;
    }
    for (int i=nth-1; i>=0; --i) {
        if (wheel[i+1][6] != wheel[i][2]) will_rotate[i] = true;
        else break;
    }
    for (int i=0; i<4; ++i) {
        if (will_rotate[i]) {
            if (i % 2 == nth % 2) rotate(i, direction);
            else rotate(i, direction * -1);
        }
    }
}

int score() {
    int sum = 0;
    for (int i=0; i<4; ++i) {
        if (wheel[i][0] == '1') sum += pow(2, i);
    }
    return sum;
}

int main() {
    cin >> wheel[0] >> wheel[1] >> wheel[2] >> wheel[3];
    int k;
    cin >> k;
    while (k--) {
        int nth, direction;
        cin >> nth >> direction;
        rotate_all(nth-1, direction);
    }
    cout << score();
    return 0;
}
