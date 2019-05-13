#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    for (int i=0; i<300000; ++i) {
        cout << rand() % 10;
    }
    cout << ' ';
    for (int i=0; i<300000; ++i) {
        cout << rand() % 10;
    }
    return 0;
}
