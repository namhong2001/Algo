#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>

using namespace std; 

struct Slot {
    int c, e;
    bool operator > (const Slot& rhs) const {
        return c*rhs.e > rhs.c*e; // c/e > rhs.c/rhs.e
    }
};
    

int main() {
    int T;
    cin >> T;
    for (int t=1; t<=T; ++t) { 
        int D, S;
        cin >> D >> S;
        vector<Slot> slots(S+1);
        slots[0] = {0, 0};
        for (int i=1; i<=S; ++i) {
            cin >> slots[i].c >> slots[i].e;
        } 
        sort(slots.begin(), slots.end(), greater<Slot>());
        vector<int> cpsum(S+1, 0);
        vector<int> epsum(S+1, 0);
        for (int i=1; i<=S; ++i) {
            cpsum[i] = cpsum[i-1] + slots[i].c;
        }
        for (int i=1; i<=S; ++i) {
            epsum[i] = epsum[i-1] + slots[i].e;
        }
        cout << "Case #" << t << ": ";
        for (int i=0; i<D; ++i) {
			cout << '\n';
            int a, b;
            cin >> a >> b;
            if (a > cpsum.back() || b > epsum.back()) {
                cout << "N";
                continue;
            } 
			/*
            if (a == cpsum.back()) {
                if(b > 0) cout << "N";
                else cout << "Y"; 
                continue;
            }
            if (b == epsum.back()) {
                if(a > 0) cout << "N";
                else cout << "Y"; 
                continue;
            }
			*/
            auto lower = prev(upper_bound(cpsum.begin(), cpsum.end(), a));
            int lower_index = lower-cpsum.begin(); 
            int need_a = a - *lower;
			int cur_esum = epsum.back() - epsum[lower_index];
            int cur_index = lower_index+1; 
			int cur_c = slots[cur_index].c;
			int cur_e = slots[cur_index].e;
            int plus_b = (cur_c-need_a)*cur_e/cur_c;
            int max_b = plus_b + epsum.back() - epsum[cur_index];
            if (1ll*(cur_c-need_a)*cur_e + 1ll*(epsum.back()-epsum[cur_index])*cur_c >= 1ll*b*cur_c) cout << "Y";
            else cout << "N"; 
        } 
        cout << '\n';
    } 
    return 0;
}

