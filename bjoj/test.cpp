#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <bitset>
#include <map>
#include <set>
#include <tuple>
#include <string.h>
#include <math.h>
#include <random>
#include <functional>
#include <assert.h>
#include <math.h>
#include <stack>
#define all(x) (x).begin(), (x).end()
#define xx first
#define yy second
#define MOD ((i64)1e9 + 7)
 
using namespace std;
 
using i64 = long long int;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;
 
vector<int> edge[100005];
int parent[100005][26];
int depth[100005];
int sub[100005];
 
void dfs(int root)
{
	depth[root] = depth[parent[root][0]] + 1;
	sub[root] = 1;
 
	for (auto& e : edge[root])
	{
		parent[e][0] = root;
		edge[e].erase(find(all(edge[e]), root));
 
		dfs(e);
		sub[root] += sub[e];
	}
}
 
int par(int x, int d)
{
	for (int i = 0; (1 << i) <= d; i++)
	{
		if (((1 << i) & d) == 0)
			continue;
 
		x = parent[x][i];
	}
 
	return x;
}
 
int lca(int x, int y)
{
	if (depth[x] > depth[y])
		x = par(x, depth[x] - depth[y]);
 
	if (depth[y] > depth[x])
		y = par(y, depth[y] - depth[x]);
 
	if (x == y)
		return x;
 
	for (int i = 20; i >= 0; i--)
	{
		if (parent[x][i] == parent[y][i])
			continue;
 
		x = parent[x][i];
		y = parent[y][i];
	}
 
	return parent[x][0];
}
 
int main()
{
	int n;
	scanf("%d", &n);
 
	for (int i = 0; i < n - 1; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
 
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
 
	dfs(1);
 
	for (int k = 1; k <= 20; k++)
		for (int i = 1; i <= n; i++)
			parent[i][k] = parent[parent[i][k - 1]][k - 1];
	
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
 
		if (a == b)
		{
			printf("%d\n", n);
			continue;
		}
 
		int l = lca(a, b);
		int ad = depth[a] - depth[l];
		int bd = depth[b] - depth[l];
 
		if (ad == bd)
		{
			int asub = par(a, ad - 1);
			int bsub = par(b, bd - 1);
			
			printf("%d\n", sub[1] - sub[asub] - sub[bsub]);
		}
		else if ((ad + bd) % 2 != 0)
		{
			printf("0\n");
		}
		else
		{
			int mid = (ad + bd) / 2;
 
			if (ad > bd)
			{
				int hsub = par(a, mid);
				int hasub = par(a, mid - 1);
 
				printf("%d\n", sub[hsub] - sub[hasub]);
			}
			else
			{
				int hsub = par(b, mid);
				int hbsub = par(b, mid - 1);
 
				printf("%d\n", sub[hsub] - sub[hbsub]);
			}
		}
	}
 
	return 0;
}
