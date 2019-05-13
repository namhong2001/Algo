#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
#include <iostream>
using namespace std;

#define MAX_V 150

struct SHARK {
	int size, spd, itg;
};

int V; // 정점수
vector<int> G[MAX_V]; //그래프의 인접리스트 표현
int match[MAX_V]; // 매칭페어
bool used[MAX_V]; // DFS 이미 조사했는지 플레그

void add(int u, int v) {
	G[u].push_back(v);
}

bool dfs(int v) {
	used[v] = 1;
	for (int i = 0; i < G[v].size(); i++) {
		int u = G[v][i], w = match[u];
		if (w < 0 || !used[w] && dfs(w)) {
			cerr << v << ' ' << u << endl;
			match[v] = u;
			match[u] = v;
			return 1;
		}
	}
	return 0;
}

int BTM() {
	int res = 0;
	memset(match, -1, sizeof match);
	int N = V/3;
	for (int v = 0; v < 2*N; v++) {
		if (match[v] < 0) {
			memset(used, 0, sizeof(used));
			if (dfs(v)){
				res++;
			}
		}
		else {
			cerr << "passed" << endl;
		}
	}
	for (int v=0; v<N*2; ++v) {	
		if (match[v] != -1) cerr << v%N+1 << ' ' << match[v]%N+1 << endl;
	}
	return res;
}

int main()
{
	int n; scanf("%d", &n);
	struct SHARK shark[50];
	V = n * 3;

	for (int i = 0; i < V; i++){
		G[i].clear();
		match[i] = 0;
		used[i] = false;
	}

	for (int i = 0; i < n; i++) scanf("%d %d %d", &shark[i].size, &shark[i].spd, &shark[i].itg);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < i; j++){
			if (i == j) continue;
			if (shark[i].size >= shark[j].size && shark[i].spd >= shark[j].spd && shark[i].itg >= shark[j].itg){
				cerr << i << endl;
				G[i].push_back(2 * n + j);
				G[n + i].push_back(2 * n + j);
			}
			else if (shark[i].size <= shark[j].size && shark[i].spd <= shark[j].spd && shark[i].itg <= shark[j].itg){
				G[j].push_back(2 * n + i);
				G[n + j].push_back(2 * n + i);
			}
		}
	}
	cerr << "0 size " << G[0].size() << endl;

	printf("%d\n", (n - BTM()));
	return 0;
}
