#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int N_MAX = 500;
int arr[N_MAX][N_MAX];
vector<vector<pair<int, int>>> tetros {
    {{0,0}, {0,1}, {0,2}, {0,3}},
    {{0,0}, {1,0}, {2,0}, {3,0}},
    {{0,0}, {0,1}, {1,0}, {1,1}},
    {{0,0}, {1,0}, {2,0}, {2,1}},
    {{0,0}, {1,0}, {2,0}, {2,-1}},
    {{0,0}, {0,1}, {0,2}, {-1,2}},
    {{0,0}, {0,1}, {0,2}, {1,2}},
    {{0,0}, {-1,0}, {-2,0}, {-2,1}},
    {{0,0}, {-1,0}, {-2,0}, {-2,-1}},
    {{0,0}, {0,-1}, {0,-2}, {-1,-2}},
    {{0,0}, {0,-1}, {0,-2}, {1,-2}},
    {{0,0}, {1,0}, {1,1}, {2,1}},
    {{0,0}, {0,1}, {-1,1}, {-1,2}},
    {{0,0}, {-1,0}, {-1,1}, {-2,1}},
    {{0,0}, {0,1}, {1,1}, {1,2}},
    {{0,0}, {0,1}, {0,2}, {1,1}},
    {{0,0}, {-1,0}, {-2,0}, {-1,1}},
    {{0,0}, {0,-1}, {0,-2}, {-1,-1}},
    {{0,0}, {1,0}, {2,0}, {1,-1}}
};

int main() {
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            cin >> arr[i][j];
        }
    }
    int max_score = 0;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            for (auto tetro : tetros) {
                int score = 0;
                for (auto p : tetro) {
                    int a = i+p.first;
                    int b = j+p.second;
                    if (a<0 || a>=n || b<0 || b>=m) {
                        score=0;
                        break;
                    } else {
                        score += arr[a][b];
                    }
                }
                max_score = max(max_score, score);
            }
        }
    }
    cout << max_score;
    return 0;
}
