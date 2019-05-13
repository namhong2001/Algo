#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <cstring>

using namespace std;

int main() {
    char s[5001];
    char* ss;
    cin >> s;
    auto comp = [](char* a, char* b){return strcmp(a, b);};
    auto myset = set<char *, decltype(comp)>(comp);
    int maxSize = 0;
    for (int i=0; i<strlen(s); ++i) {
        for (int k=1; k<=strlen(s)-i; ++k) {
            ss = (char *)malloc(k+1);
            strncpy(ss, s+i, k);
            ss[k] = '\0';
            auto result = myset.insert(ss);
            if (!result.second && k > maxSize) {
                cout << ss;
                maxSize = k;
            }
        }
    }
    cout << maxSize;
    return 0;
}
