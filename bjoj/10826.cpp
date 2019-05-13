#include <iostream>

using namespace std;

const int MAX_N = 1e4;

string fibo_memo[MAX_N+1] = {"0", "1"};

string get_str_sum(const string &a, const string &b) {
    int max_len = b.size();
    char a_cstr[max_len+1];
    const char *b_cstr = b.c_str();
    char ret_cstr[max_len+1];
    ret_cstr[max_len] = '\0';
    for (int i = 0; i<a.size(); ++i) {
        a_cstr[max_len-a.size()+i] = a[i];
    }
    if (a.size() < max_len) {
        a_cstr[0] = '0';
    }
    a_cstr[max_len] = '\0';

    int ten = 0;
    for (int i=max_len-1; i>=0; --i) {
        int cur_num = (a_cstr[i] - '0') + (b_cstr[i] - '0') + ten;
        if (cur_num >= 10) {
            ten = 1;
            cur_num -= 10;
        } else {
            ten = 0;
        }
        ret_cstr[i] = cur_num + '0';
    }

    if (ten) {
        return "1" + string(ret_cstr);
    } else {
        return string(ret_cstr);
    }
}


string fibo(int n) {
    if (!fibo_memo[n].empty()) return fibo_memo[n];
    else {
        const string &fn2 = fibo(n-2);
        const string &fn1 = fibo(n-1);
        fibo_memo[n] = get_str_sum(fn2, fn1);
        return fibo_memo[n];
    }
}

int main() {
    int n;
    cin >> n;
    cout << fibo(n);
    return 0;
}
