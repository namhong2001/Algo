#include <iostream>
#include <vector>
#include <cstring>
#include <stddef.h> /* for size_t */

using namespace std;


size_t my_strlen(const char *s) {
    const char *p = s;
    while (*s) {
        printf("%p : %c\n", s, *s);
        ++s;
    };
    printf("\n");

    return s - p;
}

int main() {
//    const char cstr[] = "string";
//    char cstr2[7] = "string";
    char cstr3[] = {'a', 't', 'r', 'i', 'n', 'g'};
//    printf("%d\n", sizeof cstr);
//    printf("%d\n", strlen(cstr));
    printf("%s\n", cstr3);
    printf("%d\n", sizeof cstr3);
    printf("%d\n", strlen(cstr3));
    printf("%d\n", my_strlen(cstr3));


//
//    int sum = 0;
//    for (auto x : cstr) {
//      sum += 1;
//    }
//    cout << "sum = " << sum << '\n'; // 결과값 7
//
//    string str = "string";
//    sum = 0;
//    for (auto x : str) {
//      sum += 1;
//    }
//    cout << "sum = " << sum << '\n'; // 결과값 6
//    return 0;
}

