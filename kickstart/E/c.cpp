#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

const int LIMIT = 1e6+1;
const int LIMIT2 = 1e6+1;

vector<int> primes;
bool isprime[LIMIT];
void eratos() {
    memset(isprime, true, sizeof(isprime));
    isprime[0] = isprime[1] = false; 
    for (int i=2; i*i<LIMIT; ++i) {
        if (!isprime[i]) continue;
        for (int j=i+i; j<LIMIT; j+=i) {
            isprime[j] = false;
        }
    }
    for (int i=2; i<LIMIT; ++i) {
        if (isprime[i]) primes.push_back(i);
    }
} 

bool decision(int a) {
    map<int,int> cnt; 
    bool twocnt2 = false;
    bool twocnt3 = false;
    bool twocnt0 = false;
    int oddcnt = 0;
    for (int p : primes) { 
        while (a%p == 0) {
            cnt[p]++;
            a/=p;
            if (p%2) oddcnt++;
        }
        if (p == 2) {
            if (cnt[p] > 3) return false;
            else if (cnt[p] == 3) twocnt3 = true;
            else if (cnt[p] == 2) twocnt2 = true;
            else if (cnt[p] == 1) return true; 
            else twocnt0 = true;
        } else if (twocnt2 && oddcnt > 1) return false;
        else if (twocnt3 && oddcnt > 0) return false;
    }
    if (a>1) {
        cnt[a]++;
        oddcnt++;
    }
    if (twocnt2 && oddcnt > 1) return false;
    else if (twocnt3 && oddcnt > 0) return false;
    else if (twocnt0) {
        int dividers = 0;
        for (auto c : cnt) {
            if (c.first == 2) continue;
            if (dividers == 0) dividers = c.second+1;
            else dividers *= c.second+1;
            if (dividers > 2) return false;
        }
    } 
    return true;
}

bool isprime2[LIMIT2];
void makePrime2(int L, int R) {
    memset(isprime2, true, sizeof(isprime2));
    for (auto p : primes) { 
        int s = L/p*p;
        if (s < L) s+=p;
        s = max(s, p+p);
        for (int i=s; i<=R; i+=p) {
            isprime2[i-L] = false;
        }
    }
} 

bool decision2(int a, int L) {
    int twocnt = 0;
    while (a%2 == 0) {
        twocnt++;
        a/=2;
        if (twocnt > 3) return false;
    } 
    if (twocnt == 3) {
        if (a == 1) return true;
        else return false;
    } else if (twocnt == 2) {
        if (isprime2[a-L] || a == 1) return true;
        else return false;
    } else if (twocnt == 1) return true;
    else {
        if (isprime2[a-L] || a == 1) return true;
        else return false;
    }
} 

int main() {
    eratos();
    int T;
    cin >> T; 
    for (int t=1; t<=T; ++t) {
        int L, R;
        cin >> L >> R;
        makePrime2(L, R); 
        int ans = 0;
        for (int i=L; i<=R; ++i) {
            if (decision2(i, L)) {
                ans++;
            }      
        } 
        cout << "Case #" << t << ": " << ans << '\n';
    } 
    return 0;
}

