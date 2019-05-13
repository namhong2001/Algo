#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t=1; t<=T; ++t) {
        int P, Q;
        cin >> P >> Q;
        vector<int> wcoord;
        vector<int> ecoord;
        vector<int> scoord;
        vector<int> ncoord;
        vector<int> xcart(1, 0);
        vector<int> ycart(1, 0);
        for (int p=0; p<P; ++p) {
            int x, y;
            string d;
            cin >> x >> y >> d;
            if (d == "W") { wcoord.push_back(x); xcart.push_back(x+1); }
            else if (d == "E") { ecoord.push_back(x); xcart.push_back(x+1); }
            else if (d == "S") { scoord.push_back(y); ycart.push_back(y+1); }
            else if (d == "N") { ncoord.push_back(y); ycart.push_back(y+1); }
        }
        sort(wcoord.begin(), wcoord.end());
        sort(ecoord.begin(), ecoord.end());
        sort(scoord.begin(), scoord.end());
        sort(ncoord.begin(), ncoord.end());
        sort(xcart.begin(), xcart.end());
        sort(ycart.begin(), ycart.end());

        int wcnt = wcoord.size(), ecnt = 0;
        int wpos = 0, epos = 0;
        int xmax = wcoord.size();
        int xpos = 0;
        for (int i=0; i<xcart.size(); ++i) {
            while(wpos < wcoord.size() && wcoord[wpos] <= xcart[i]) {
                wcnt--;
                wpos++;
            }
            while(epos < ecoord.size() && ecoord[epos] < xcart[i]) {
                ecnt++;
                epos++;
            }
            if (wcnt + ecnt > xmax) {
                xmax = wcnt + ecnt;
                xpos = xcart[i];
            }
        }
        int scnt = scoord.size(), ncnt = 0;
        int spos = 0, n_pos = 0;
        int ymax = scoord.size();
        int ypos = 0;
        for (int i=0; i<ycart.size(); ++i) {
            while(spos < scoord.size() && scoord[spos] <= ycart[i]) {
                scnt--;
                spos++;
            }
            while(n_pos < ncoord.size() && ncoord[n_pos] < ycart[i]) {
                ncnt++;
                n_pos++;
            }
            if (scnt + ncnt > ymax) {
                ymax = scnt + ncnt;
                ypos = ycart[i];
            }
        }
        cout << "Case #" << t << ": " << xpos << ' ' << ypos << endl;
    }

    return 0;
}
