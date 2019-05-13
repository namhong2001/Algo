#include <iostream>
#include <vector>


using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t=1; t<=T; ++t) {
        int P, Q;
        cin >> P >> Q;
        vector<vector<int>> votes(Q+1, vector<int>(Q+1, 0));
        for (int p=0; p<P; ++p) {
            int x, y;
            string d;
            cin >> x >> y >> d;
            if (d == "W") {
                for (int i=0; i<x; ++i) {
                    for (int j=0; j<=Q; ++j) {
                        votes[i][j]++;
                    }
                }
            }
            if (d == "E") {
                for (int i=x+1; i<=Q; ++i) {
                    for (int j=0; j<=Q; ++j) {
                        votes[i][j]++;
                    }
                }
            }
            if (d == "S") {
                for (int i=0; i<=Q; ++i) {
                    for (int j=0; j<y; ++j) {
                        votes[i][j]++;
                    }
                }
            }
            if (d == "N") {
                for (int i=0; i<=Q; ++i) {
                    for (int j=y+1; j<=Q; ++j) {
                        votes[i][j]++;
                    }
                }
            }
        }
        int max_votes = 0;
        int ansx, ansy;
        for (int i=0; i<=Q; ++i) {
            for (int j=0; j<=Q; ++j) {
                if (votes[i][j] > max_votes) {
                    max_votes = votes[i][j];
                    ansx = i;
                    ansy = j;
                }
            }
        }

        cout << "Case #" << t << ": " << ansx << ' ' << ansy << endl;
    }

    return 0;
}
