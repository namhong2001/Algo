#include <iostream>

using namespace std;

const int N_MAX = 100000;

int in[N_MAX];
int post[N_MAX];

void print_pre(int in_start, int post_start, int n) {
    if (n==0) return;
    if (n==1) {
        cout << in[in_start] << ' ';
        return;
    };
    int root = post[post_start+n-1];
    int root_pos_in;
    for (int i=in_start; i<in_start+n; ++i) {
        if (in[i] == root) root_pos_in = i;
    }
    cout << root << ' ';
    int left_cnt = root_pos_in - in_start;
    int right_cnt = n-left_cnt-1;
    print_pre(in_start, post_start, left_cnt);
    print_pre(root_pos_in+1, post_start+left_cnt, right_cnt);
}


int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> in[i];
    }
    for (int i=0; i<n; ++i) {
        cin >> post[i];
    }
    print_pre(0, 0, n);

    return 0;
}
