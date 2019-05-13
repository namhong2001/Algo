#include <cstdio>
#include <list>
#include <iterator>

using namespace std;

int main() {
    list<char> my_list;
    char c;
    while (true) {
        scanf("%c", &c);
        if (c < 'a' || c > 'z') {
            break;
        }
        my_list.push_back(c);
    }
    list<char>::iterator my_pos = my_list.end();
    int n;
    scanf("%d", &n);
    char operation;
    while(n--) {
        scanf(" %c", &operation);
        if (operation == 'L') {
            if (my_pos != my_list.begin()) {
                --my_pos;
            }
        } else if (operation == 'D') {
            if (my_pos != my_list.end()) {
                ++my_pos;
            }
        } else if (operation == 'B') {
            if (my_pos != my_list.begin()) {
                my_list.erase(prev(my_pos));
            }
        } else if (operation == 'P') {
            char new_char;
            scanf(" %c", &new_char);
            my_list.insert(my_pos, new_char);
        }
    }
    for (auto i : my_list) {
        printf("%c", i);
    }
    return 0;
}
