#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int h, w, n;
        cin >> h >> w >> n;
        string f = to_string(n%h ? n%h : h);
        string r = to_string((n-1)/h+1);
        if ((n-1)/h+1 < 10) {
            r = "0"+r;
        }
        cout << f << r << endl;
    }

    return 0;
}
