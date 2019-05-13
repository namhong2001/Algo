#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <memory.h>

#define INF 987654321

using namespace std;

typedef pair<int, int> pii;

vector<vector<int>> adj, c, f;

int main()
{
    int tc;
    scanf("%d", &tc);

    while (tc--)
    {
        int n, m;
        scanf("%d %d", &n, &m);

        f = c = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
        adj = vector<vector<int>>(n + 1);

        vector<pii> vc;

        for (int i = 0; i < m; i++)
        {
            int from, to, val;
            scanf("%d %d %d", &from, &to, &val);

            adj[from].push_back(to);
            adj[to].push_back(from); // 역방향 간선

            c[from][to] += val;

            vc.push_back({ from,to });
        }

        // 에드몬드 카프 알고리즘
        int totalFlow = 0, S = 1, T = n;
        while (1)
        {
            vector<int> prev(n + 1, -1);

            queue<int> q;
            q.push(S);

            while (!q.empty() && prev[T] == -1)
            {
                int cur = q.front();
                q.pop();

                for (int i = 0; i < adj[cur].size(); i++)
                {
                    int next = adj[cur][i];

                    if (prev[next] != -1)
                        continue;

                    if (c[cur][next] - f[cur][next] > 0)
                    {
                        q.push(next);
                        prev[next] = cur;
                    }
                }
            }

            if (prev[T] == -1)
                break;

            int flow = INF;

            for (int i = T; i != S; i = prev[i])
                flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);

            for (int i = T; i != S; i = prev[i])
            {
                f[prev[i]][i] += flow;
                f[i][prev[i]] -= flow;
            }
            totalFlow += flow;
        }

        // 완전 중요한 간선인지 확인
        int ans = 0;
        for (int i = 0; i < vc.size(); i++)
        {
            int S = vc[i].first;
            int T = vc[i].second;

            vector<int> prev(n + 1, -1);

            queue<int> q;
            q.push(S);

            while (!q.empty() && prev[T] == -1)
            {
                int cur = q.front();
                q.pop();

                for (int i = 0; i < adj[cur].size(); i++)
                {
                    int next = adj[cur][i];
                    if (prev[next] != -1)
                        continue;

                    if (c[cur][next] - f[cur][next] > 0)
                    {
                        prev[next] = cur;
                        q.push(next);
                    }
                }
            }

            if (prev[T] == -1)
                ans++;
        }

        printf("%d\n", ans);
    }

    return 0;
}
