#include <iostream>
#include <vector>

using namespace std;

const int MAP_MAX = 100;
bool map[MAP_MAX+1][MAP_MAX+1] = {};

void draw(int x, int y, int d, int g) {
    vector<int> directions {d};
    map[x][y] = true;
    for (int gen=0; gen<=g; ++gen) {
        for (int j=directions.size()/2; j<directions.size(); ++j) {
            switch(directions[j]) {
                case 0:
                    x++;
                    break;
                case 1:
                    y--;
                    break;
                case 2:
                    x--;
                    break;
                case 3:
                    y++;
                    break;
            }
            map[x][y] = true;
        }
        for (int j=directions.size()-1; j>=0; --j) {
            int new_direction = directions[j] < 3 ? directions[j]+1 : 0;
            directions.push_back(new_direction);
        }
    }
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        draw(x, y, d, g);
    }
    int cnt = 0;
    for (int i=0; i<MAP_MAX; ++i) {
        for (int j=0; j<MAP_MAX; ++j) {
            if (map[i][j] && map[i][j+1] && map[i+1][j] && map[i+1][j+1]) cnt++;
        }
    }
    cout << cnt;
    return 0;
}
