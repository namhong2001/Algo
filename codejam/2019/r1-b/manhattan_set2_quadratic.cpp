#include <iostream>
#include <vector>


using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t=1; t<=T; ++t) {
        int P, Q;
        cin >> P >> Q;
        vector<int> X(P);
        vector<int> Y(P);
        vector<string> D(P);
        for (int p=0; p<P; ++p) {
            int x, y;
            string d;
            cin >> x >> y >> d;
            X[p] = x;
            Y[p] = y;
            D[p] = d;
        }

        vector<int> xcart(1, 0);
        vector<int> ycart(1, 0);
        for (int p=0; p<P; ++p) {
            if (D[p] == "W" || D[p] == "E") {
                xcart.push_back(X[p]+1);
            }
            else {
                ycart.push_back(Y[p]+1);
            }
        }
        vector<int> xvotes(xcart.size(), 0);
        vector<int> yvotes(ycart.size(), 0);
        for (int p=0; p<P; ++p) {
            if (D[p] == "W") {
                for (int i=0; i<xcart.size(); ++i) {
                    if (xcart[i] < X[p]) xvotes[i]++;
                }
            } else if (D[p] == "E") {
                for (int i=0; i<xcart.size(); ++i) {
                    if (xcart[i] > X[p]) xvotes[i]++;
                }
            } else if (D[p] == "S") {
                for (int i=0; i<ycart.size(); ++i) {
                    if (ycart[i] < Y[p]) yvotes[i]++;
                }
            } else if (D[p] == "N") {
                for (int i=0; i<ycart.size(); ++i) {
                    if (ycart[i] > Y[p]) yvotes[i]++;
                }
            }
        }
        int xmax = -1;
        int ymax = -1;
        int ansx = 0, ansy = 0;
        for (int i=0; i<xvotes.size(); ++i) {
            if (xvotes[i] > xmax || (xvotes[i] == xmax && xcart[i] < ansx)) {
                xmax = xvotes[i];
                ansx = xcart[i];
            }
        }
        for (int i=0; i<yvotes.size(); ++i) {
            if (yvotes[i] > ymax || (yvotes[i] == ymax && ycart[i] < ansy)) {
                ymax = yvotes[i];
                ansy = ycart[i];
            }
        }
        cout << "Case #" << t << ": " << ansx << ' ' << ansy << endl;
    }

    return 0;
}
