#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")

#define fi first
#define se second

const int N = 330;
const int MAGIC = 130;

using namespace std;

int n;
int m;
int k;
int p[N];
int s[N];
int a[N][N];
int r[N][N];

int get(int x)
{
        return p[x] == x ? x : p[x] = get(p[x]);
}

void solve()
{
        cin >> n >> m >> k;
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        cin >> a[i][j];
                }
        }
        for(int i = 1; i <= n; i++){
                set < pair < int, int > > s;
                for(int j = m; j >= 1; j--){
                        if(j == m){
                                r[i][j] = m;
                        } else{
                                r[i][j] = r[i][j + 1];
                        }
                        while(!s.empty() && (abs((--s.end())->fi - a[i][j]) > k || abs(s.begin()->fi - a[i][j]) > k)){
                                s.erase({a[i][r[i][j]], r[i][j]});
                                r[i][j]--;
                        }
                        s.insert({a[i][j], j});
                }
        }
        int res = 0;
        vector < pair < int, int > > v;
        for(int j = 1; j <= m; j++){
                v.clear();
                for(int i = 1; i <= n; i++){
                        v.push_back({r[i][j], i});
                        s[i] = 1;
                        p[i] = 0;
                }
                sort(v.begin(), v.end());
                reverse(v.begin(), v.end());
                for(auto t: v){
                        int x = t.se;
                        p[x] = x;
                        if(x > 1 && p[x - 1]){
                                int y = get(x - 1);
                                p[y] = x;
                                s[x] += s[y];
                        }
                        if(x < n && p[x + 1]){
                                int y = get(x + 1);
                                p[y] = x;
                                s[x] += s[y];
                        }
                        res = max(res, s[x] * (t.fi - j + 1));
                }
        }
        cout << res << "\n";
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int T;
        cin >> T;
        for(int i = 1; i <= T; i++){
                cout << "Case #" << i << ": ";
                solve();
        }
}
