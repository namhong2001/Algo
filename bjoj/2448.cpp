#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    char* prev = new char[2*n];
    char* now = new char[2*n];
    prev[2*n-1] = '\0';
    now[2*n-1] = '\0';

    for(int i=0; i<2*n-1; ++i) {
        prev[i] = ' ';
    }
    prev[n-1] = '*';
    cout << prev << '\n';

    int line = n;
    while(--line) {
        for (int i=0; i<2*n-1; ++i) {
            now[i] = ' ';
        }
        switch(line % 3) {
            case 0:
                for(int i=0; i<2*n-1; ++i) {
                    if (prev[i] == '*' && prev[i-1] == ' ' && prev[i-2] == ' ') {
                        now[i-1] = '*';
                    } else if (prev[i] == '*' && prev[i+1] == ' ' && prev[i+2] == ' ') {
                        now[i+1] = '*';
                    }
                }
                break;

            case 2:
                for(int i=0; i<2*n-1; ++i) {
                    if (prev[i] == '*') {
                        now[i-1] = '*';
                        now[i+1] = '*';
                    }
                }
                break;

            case 1:
                for(int i=0; i<2*n-1; ++i) {
                    if (prev[i] == '*' && prev[i+1] == ' ' && prev[i+2] == '*') {
                        now[i-1] = '*';
                        now[i] = '*';
                        now[i+1] = '*';
                        now[i+2] = '*';
                        now[i+3] = '*';
                    }
                }
                break;
        }
        cout << now << '\n';
        char* temp = prev;
        prev = now;
        now = temp;
    }
    return 0;
}


