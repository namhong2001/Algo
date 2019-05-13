#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    bool arr[1001] = {false};
    arr[0] = true;
    arr[1] = true;
    for (int i=2; i<32; ++i) {
        for (int j=i; i*j<1001; ++j) {
            arr[i*j] = true;
        }
    }

    int cnt = 0;
    while(n--) {
        int a;
        cin >> a;
        if (!arr[a]) {
            ++cnt;
        }
    }
    cout << cnt;


    return 0;
}
