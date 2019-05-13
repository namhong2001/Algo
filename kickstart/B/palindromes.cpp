#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        int ans = 0;
        vector<vector<int>> ps(26, vector<int>(n + 1, 0));
        for (int i = 0; i < 26; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (s[j] == 'A' + i)
                    ps[i][j + 1] = ps[i][j] + 1;
                else
                    ps[i][j + 1] = ps[i][j];
            }
        }

        while (q--)
        {
            int l, r;
            cin >> l >> r;
            int odd_cnt = 0;
            for (int i = 0; i < 26; ++i)
            {
                if ((ps[i][r] - ps[i][l - 1]) % 2)
                    odd_cnt++;
            }
            if (odd_cnt < 2)
                ans++;
        }
        cout << "Case #" << t << ": " << ans << '\n';
    }

    return 0;
}
