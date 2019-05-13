#include <iostream>
#include <vector>

using namespace std;


int cal(const string &s, int start, int end, int arr[]) {
    int sum = 0;
    int pos = start;
    if (end-start == 1) {
        return s[start] == '(' ? 2 : 3;
    }
    for (int i=start; i<=end; ++i) {
        if (arr[i] == pos) {
            if (i == end && pos == start) {
                sum += cal(s, start+1, end-1, arr) * ( s[pos]=='(' ? 2 : 3);
            } else {
                sum += cal(s, pos, i, arr);
                pos = i+1;
            }
        }
    }
    return sum;
}

int main() {
    string s;
    cin >> s;
    int l = s.size();
    int arr[l];
    for (int i=0; i<l; ++i) {
        arr[i] = -1;
    }

    int stk1 = 0;
    int stk2 = 0;
    vector<int> ppos;
    vector<int> bpos;

    for (int i=0; i<l; ++i) {
        if (s[i] == '(') {
            stk1++;
            ppos.push_back(i);
        } else if (s[i] == '[') {
            stk2++;
            bpos.push_back(i);
        } else if (s[i] == ')') {
            if (i>0 && s[i-1] == '[') {
                cout << 0;
                return 0;
            }
            stk1--;
            if (stk1 < 0) {
                cout << 0;
                return 0;
            }
            arr[i] = ppos.back();
            ppos.pop_back();
        } else if (s[i] == ']') {
            if (i>0 && s[i-1] == '(') {
                cout << 0;
                return 0;
            }
            stk2--;
            if (stk2 < 0) {
                cout << 0;
                return 0;
            }
            arr[i] = bpos.back();
            bpos.pop_back();
        }
    }
    cout << cal(s, 0, l-1, arr);
    return 0;
}
