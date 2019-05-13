#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<bool> my_bool(1e9);
    for(int i=0; i<1e9; ++i) {
        my_bool[i] = true;
        cout << i << ' ';
    }
    return 0;
}
