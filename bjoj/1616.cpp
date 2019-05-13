#include <cstdio>
#include <queue>
#include <cmath>
#include <stack>

using namespace std;

int k, m;
int cases;
vector<int> edges;

void dfs(int root) {
    stack<int> st;
    st.push(root);
    while (!st.empty()) {
        int here = st.top();
        if (edges[here] >= 0) {
            int there = (here * k + edges[here]--) % cases;
            st.push(there);
        } else {
            if (st.size() > 1) {
                printf("%d ", here%k);
            }
            st.pop();
        }
    }
}

int main() {
    scanf("%d%d", &k, &m);
    if (m == 1) {
        for (int i=0; i<k; ++i) {
            printf("%d ", i);
        }
        return 0;
    }
    cases = pow(k, m-1);
    edges = vector<int>(cases, k-1);
    dfs(0);
    return 0;
}
