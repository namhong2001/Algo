#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int main() {
    srand(time(0));
	cout << "1 1"<< '\n';
    for (int i=0; i<4; ++i) {
		cout << (rand() % 20000 - 10000) << ' ';
    } 
	cout << '\n'; 
    for (int i=0; i<4; ++i) {
		cout << (rand() % 20000 - 10000) << ' ';
    } 
    cout << '\n';
    return 0;
}
