#include <cstdio>
#include <iostream>

using namespace std;


int main() {
    int x, y;
    const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    const string day[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    int diff = 0;

    cin >> x >> y;
    for (int i=0; i<x-1; ++i) {
        diff += days[i];
    }
    diff += y-1;
    cout << day[diff%7];
//    printf("%s", day[diff%7]);

    return 0;
}


