#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
    string str;
//    scanf("%s", &str);
    cin >> str;
    printf("%s\n", str);
    string str4 = "Hello";
//    const char str2[] = "Hello";
//    cout << str << '\n';
//    printf("%s\n", str); // Hello2m
//    cout << str << '\n';
    cout << sizeof str << '\n';
    cout << str.length() << '\n';
    cout << str4 << '\n';
    cout << sizeof str4 << '\n';
    cout << str4.length() << '\n';


//    cout << sizeof str << '\n';  // 6
//    cout << sizeof str2 << '\n'; // 6
//    cout << strlen(str) << '\n'; // 5
//    cout << strlen(str2) << '\n'; // 5
//    cout << strcmp(str, str2) << '\n'; // return 0 which means equal.
//    printf("%d\n", str2[5] == '\0');
//    cout << str2[5] == '\0' << '\n'; // '\0'
    return 0;
}
