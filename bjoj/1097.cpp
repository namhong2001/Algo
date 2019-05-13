#include <iostream>
#include <vector>

using namespace std;

vector<int> getPartialMatch(const string& N) {
    int m = N.size();
    vector<int> pi(m, 0);
    int matched = 0;
    for (int i=1; i<m; ++i) {
        while(matched > 0 && N[i] != N[matched]) {
            matched = pi[matched-1];
        }
        if(N[i] == N[matched]) {
            ++matched;
            pi[i] = matched;
        }
    }
    return pi;
}

vector<int> kmpSearch(const string& H, const string& N) {
    int h = H.size();
    int n = N.size();
    vector<int> pi = getPartialMatch(N);
    vector<int> ret;
    int matched = 0;
    for (int i=0; i<h; ++i) {
        while(matched > 0 && H[i] != N[matched]) {
            matched = pi[matched-1];
        }
        if(H[i] == N[matched]) {
            ++matched;
            if (matched == n) {
                ret.push_back(i - matched + 1);
                matched = pi[matched-1];
            }
        }
    }
    return ret;
}


void checkStr(vector<string> &arr, string &pre, string &flag, int k, int &cnt) {
//    cout << " " << pre << " " << flag << " " << k << " " << cnt << endl;
    if (flag.find('0') == -1 && kmpSearch(pre + pre, pre).size() == k+1) {
        cnt++;
    }
    for (int i=0; i<flag.size(); ++i) {
        if (flag[i] == '0') {
            string newFlag = flag;
            newFlag[i] = '1';
            string newStr = pre+arr[i];
            checkStr(arr, newStr, newFlag, k, cnt);
        }
    }
}


int main() {
    int n;
    cin >> n;
    vector<string> arr(n);
    for(int i=0; i<n; ++i) {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    int cnt = 0;
    string flag(n, '0');
    string emptyStr = "";
    checkStr(arr, emptyStr, flag, k, cnt);
    cout << cnt;
    return 0;
}
