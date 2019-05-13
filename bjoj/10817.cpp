#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int num[3];
    cin >> num[0] >> num[1] >> num[2];
    qsort(num, 3, sizeof (*num), [](const void* a, const void* b) {
        int x, y;
        x = *(const int *)a;
        y = *(const int *)b;
        if (x < y) return -1;
        if (x > y) return 1;
        return 0;


    });
    printf("%d", num[1]);
    return 0;
}
