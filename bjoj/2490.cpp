#include <iostream>

using namespace std;

char cases[5] = {'D', 'C', 'B', 'A', 'E'};

int main() {
    for (int i=0; i<3; ++i) {
        int cnt = 0;
        for (int j=0; j<4; ++j) {
            int a;
            cin >> a;
            if (a == 1) cnt++;
        }
        cout << cases[cnt] << endl;
    }

    return 0;
}
