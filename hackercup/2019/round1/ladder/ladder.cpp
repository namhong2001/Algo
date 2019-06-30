#include <iostream>
#include <tuple>
#include <vector>
#include <iterator>
#include <queue>
#include <cstring>
#include <algorithm>
#include <set> 

using namespace std;

typedef tuple<int,int,int> LDDR;  // x, a, b;
typedef pair<int,int> pii;

const int INF = 987654321; 

int N, H;
int capacity[52][52], flow[52][52]; 
const int SRC = 50;
const int DEST = 51;

bool isIntersect(int a, int b, int na, int nb) {
	return !(a >= nb || na >= b);
} 

void make_graph(vector<LDDR> &ladders) {
	memset(capacity, 0, sizeof(capacity));
	sort(ladders.begin(), ladders.end());
	for (int i=0; i<N; ++i) {
		int x, a, b;
		tie(x, a, b) = ladders[i];
		if (a == 0) capacity[SRC][i] = INF;
		if (b == H) capacity[i][DEST] = INF;
		// to left
		set<pii> ranges;
		for (int j=i-1; j>=0; --j) {
			int nx, na, nb;
		    tie(nx, na, nb)	= ladders[j]; 
			if (!isIntersect(a, b, na, nb)) continue;
			int lo = max(na, a), hi = min(nb, b);
			int weight = 0;
			for (pii r : ranges) {
				if (r.first > lo) {
					weight += min(hi, r.first) - lo;
				}
				lo = max(lo, r.second);
			}
			if (hi > lo) weight += hi - lo;
			ranges.emplace(na, nb);
			capacity[i][j] = weight;
		}
		// to right
		ranges.clear();
		for (int j=i+1; j<N; ++j) {
			int nx, na, nb;
		    tie(nx, na, nb)	= ladders[j]; 
			if (!isIntersect(a, b, na, nb)) continue;
			int lo = max(na, a), hi = min(nb, b);
			int weight = 0;
			for (pii r : ranges) {
				if (r.first > lo) {
					weight += min(hi, r.first) - lo;
				}
				lo = max(lo, r.second);
			}
			if (hi > lo) weight += hi - lo;
			ranges.emplace(na, nb);
			capacity[i][j] = weight;
		}
	}
} 
	
int networkFlow(int source, int sink) { // source = 50, sink = 51;
  memset(flow, 0, sizeof(flow));
  int totalFlow = 0;
  while(true) {
    vector<int> parent(52, -1);
    queue<int> q;
    parent[source] = source;
    q.push(source);
    while(!q.empty() && parent[sink] == -1) {
      int here = q.front(); q.pop();
      for(int there = 0; there < 52; ++there) {
        if (capacity[here][there] - flow[here][there] > 0 && parent[there] == -1) {
          q.push(there);
          parent[there] = here;
        }
      }
    }
    if (parent[sink] == -1) break;
    int amount = INF;
    for(int p = sink; p != source; p = parent[p]) {
      amount = min(capacity[parent[p]][p] - flow[parent[p]][p], amount);
    }
    for (int p = sink; p!=source; p = parent[p]) {
      flow[parent[p]][p] += amount;
      flow[p][parent[p]] -= amount;
    }
    totalFlow += amount;
  }
  return totalFlow;
}

int main() {
	int T;
	cin >> T;
	for (int t=1; t<=T; ++t) {
		cin >> N >> H;
		vector<LDDR> ladders;
		bool isOk = true;
		for (int i=0; i<N; ++i) {
			int x, a, b;
			cin >> x >> a >> b;
			ladders.emplace_back(x, a, b);
			if (a == 0 && b == H) {
				isOk = false;
			} 
		}
		if (!isOk) {
			cout << "Case #" << t << ": " << -1 << '\n';
			continue;
		}
		make_graph(ladders); 
		cout << "Case #" << t << ": " << networkFlow(SRC, DEST) << '\n';
	}
	return 0;
} 
