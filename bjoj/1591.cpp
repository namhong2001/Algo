#include <iostream>
#include <map>
#include <vector>
#include <queue>

#define V vector<int> // vertex
#define SS vector<int> // subsequence

using namespace std;


int n, m;
map<V, int> indegree;
map<V, int> outdegree;
map<V, queue<int>> adj;
set<SS> subsequences;
set<V> vertices;

int main() {
    cin >> n >> m;
    for (int i=0; i<n-m+1; ++i) {
        SS subsequence;
        for (int j=0; j<m; ++j) {
            int a;
            cin >> a;
            subsequence.push_back(a);
        }
        subsequence.insert(subsequence);
        vertices.insert(V(subsequence.begin()+1, subsequence.end()));
    }
    for (SS subsequence : subsequences) {

    }

    return 0;
}
