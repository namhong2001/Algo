#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

typedef long long ll;
#define INF (1<<30)

#define T (1<<18)

ll tree[T];

void add(int pos, ll val){
	for(int i=pos;i<T;i=((i)|(i+1))) tree[i] += val;
}

ll sum(int pos){
	ll ans = 0;
	for(int i=pos;i>0;i=((i)&(i-1))) ans += tree[i-1];
	return ans;
}
	
int N,K;
int c[100010],d[100010];

int P,Q;
vector <pair <int, int> > p,q;
vector <pair <pair <int, int>, int> > p_event, q_event;

ll sweep(void){
	int i;
	ll ans = 0;
	
	REP(i,p.size()){
		int x = p[i].first;
		int y = p[i].second;
		p_event.push_back(make_pair(make_pair(x, y + INF), 0));
	}
	
	vector <int> added;
	
	sort(p_event.begin(), p_event.end());
	
	REP(i,p_event.size()){
		int x = p_event[i].first.first;
		int y = p_event[i].first.second;
		int type = p_event[i].second;
		
		if(type == 0){
			y -= INF;
			added.push_back(y);
			add(y, 1);
		} else {
			ans += sum(y) * type;
		}
	}
	
	REP(i,added.size()) add(added[i], -1);
	
	return ans;
}

void add_P(int x1, int y1, int x2, int y2, int c){
	if(x1 >= x2 || y1 >= y2) return;
	p_event.push_back(make_pair(make_pair(x1, y1), c));
	p_event.push_back(make_pair(make_pair(x1, y2), -c));
	p_event.push_back(make_pair(make_pair(x2, y1), -c));
	p_event.push_back(make_pair(make_pair(x2, y2), c));
}

void add_Q(int x1, int y1, int x2, int y2, int c){
	if(x1 >= x2 || y1 >= y2) return;
	q_event.push_back(make_pair(make_pair(x1, y1), c));
	q_event.push_back(make_pair(make_pair(x1, y2), -c));
	q_event.push_back(make_pair(make_pair(x2, y1), -c));
	q_event.push_back(make_pair(make_pair(x2, y2), c));
}

ll main3(int L, int R){
	int i;
	
	p_event.clear();
	q_event.clear();
	
	int M = (L + R) / 2;
	p.clear();
	q.clear();
	
	int x = 0, y = 0;
	for(i=M-1;i>=L;i--){
		x = max(x, c[i]);
		y = max(y, d[i]);
		p.push_back(make_pair(x, y));
	}
	
	x = y = 0;
	for(i=M;i<R;i++){
		x = max(x, c[i]);
		y = max(y, d[i]);
		q.push_back(make_pair(x, y));
	}
	
	P = p.size();
	Q = q.size();
	
	REP(i,P) if(abs(p[i].first - p[i].second) <= K){
		add_Q(0, 0, p[i].first + 1, p[i].second + 1, 1);
	}
	
	REP(i,Q) if(abs(q[i].first - q[i].second) <= K){
		add_P(0, 0, q[i].first + 1, q[i].second + 1, 1);
		add_P(q[i].first, q[i].second, q[i].first + 1, q[i].second + 1, -1);
	}
	
	REP(i,P){
		int a = p[i].first;
		int b = p[i].second;
		add_Q(max(a+1, b-K), 0, b+K+1, b, 1);
		add_Q(0, max(b+1, a-K), a, a+K+1, 1);
	}
	
	ll ans = sweep();
	swap(p, q);
	swap(p_event, q_event);
	ans += sweep();
	
	return ans;
}

ll conquer(int L, int R){
	if(R - L == 1){
		if(abs(c[L] - d[L]) <= K) return 1;
		return 0;
	}
	
	int M = (L + R) / 2;
	ll ans = conquer(L, M) + conquer(M, R);
	ans += main3(L, R);
	
	return ans;
}
	
void main2(void){
	int i;
	
	cin >> N >> K;
	REP(i,N) scanf("%d", &c[i]);
	REP(i,N) scanf("%d", &d[i]);

//	N = 100000;
//	K = 10000;
//	REP(i,N) c[i] = rand() % 100000;
//	REP(i,N) d[i] = rand() % 100000;
	
	ll ans = conquer(0, N);
	cout << ans << endl;
}	
	
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(void){
	int TC,tc;
	cin >> TC;
	REP(tc,TC){
		printf("Case #%d: ", tc + 1);
		main2();
	}
	return 0;
}
