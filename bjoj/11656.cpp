#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> getSuffixArr(string &str) {
    int str_len = str.size();
    vector<int> ret;
    vector<int> group;
    for (int i=0; i<str_len; ++i) {
        group.push_back(str[i]);
        ret.push_back(i);
    }
    group.push_back(-1);
    int t;

    for (t=1; t < str.size(); t=2*t) {
        auto comp = [&group, &t](const int a, const int b){
            if (group[a] != group[b]) return group[a] < group[b];
            else {
                return group[a+t] < group[b+t];
            }
        };
        sort(ret.begin(), ret.end(), comp);
        vector<int> new_group(str_len+1);
        int prio = 0;
        new_group[ret[0]] = prio;
        for (int i=1; i<str_len; ++i) {
            if (comp(ret[i-1], ret[i])) {
                ++prio;
            }
            new_group[ret[i]] = prio;
        }
        new_group[str_len] = -1;
        group = new_group;


    }
    return ret;
}



int main() {
    string str;
    cin >> str;
    vector<int> suffixArr = getSuffixArr(str);
    for (auto i : suffixArr) {
        cout << str.substr(i) << endl;
    }
    return 0;
}
