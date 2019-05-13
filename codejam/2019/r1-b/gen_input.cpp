#include <iostream>
#include <ctime>
#include <cstdlib>


using namespace std;

const string dir[4] = {"W", "E", "S", "N"};

int main() {
    srand(time(nullptr));
    int T = 1;
    cout << T << endl;
    while (T--) {
        int N = 10, K = rand()%((int)1e5+1);

        cout << N << ' ' << K << endl;
        for (int i=0; i<N; ++i) {
            cout << rand()%((int)1e5+1) << ' ';
        }
        cout << endl;
        for (int i=0; i<N; ++i) {
            cout << rand()%((int)1e5+1) << ' ';
        }
        cout << endl;
    }

    return 0;
}
