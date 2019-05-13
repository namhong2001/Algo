#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int c, n;
    int score[1000] = {0};
    cin >> c;
    while(c--) {
        cin >> n;
        int it = n;
        int sum = 0;
        int cnt = 0;
        while(it--) {
            cin >> score[it];
            sum += score[it];
        }
        double avg = (double)sum / n;
        it = n;
        while(it--) {
            if (score[it] > avg) {
                cnt++;
            }
        }
        cout << fixed << setprecision(3) << (double) cnt / n * 100 << "%\n";

    }
    return 0;
}
