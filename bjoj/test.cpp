#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int board[200][200];
int cache[31][200][200];
int K, W, H;

class Position {
    int r, c, k;

    Position() = default;
    Position(int r, int c, int k) : r(r), c(c), k(k) {}
};

class Monkey extends Position {
    Monkey() {
        super();
    }
    const int dx[4];
    const int dy[4];
    bool canMove();
    int move();

    public:
        static int dx[4];
        static int dy[4];
}


for (int i=0; i<4; ++i) {
    int nx = x + Monkey.dx[i];
}

typedef struct {
    int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
} Monkey;

typedef struct {
    int dx[8] = {-1, -2, -1, -2, 1, 2, 1, 2},
        dy[8] = {-2, -1, 2, 1, -2, -1, 2, 1};
} Horse;

static Monkey monkey;
static Horse horse;

bool isRange(int r, int c) {
    return r>=0 && r<H && c>=0 && c<W;
}

int main() {
    cin >> K >> W >> H;

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> board[i][j];
        }
    }

    int ans = 987654321;
    queue<Position> q;
    Position start(0, 0, 0);
    memset(cache, -1, sizeof(cache));
    q.push(start);
    cache[0][0][0] = 0;

    while(!q.empty()) {
        Position here = q.front();
        q.pop();
        if(here.r == H-1 && here.c == W - 1) {
            ans = min(ans, cache[here.k][here.r][here.c]);
            continue;
        }

        Position there(0,0,here.k);
        for(int i=0; i<4; ++i) {
            there.r = here.r + monkey.dx[i]; there.c = here.c + monkey.dy[i];
            if(!isRange(there.r, there.c))
                continue;
            if(board[there.r][there.c])
                continue;
            if(cache[there.k][there.r][there.c] != -1)
                continue;
            q.push(there);
            cache[there.k][there.r][there.c] = cache[here.k][here.r][here.c] + 1;
        }

        there.k++;
        if(here.k < K) {
            for (int i = 0; i < 8; ++i) {
                there.r = here.r + horse.dx[i], there.c = here.c + horse.dy[i];
                if (!isRange(there.r, there.c))
                    continue;
                if (board[there.r][there.c])
                    continue;
                if(cache[there.k][there.r][there.c] != -1)
                    continue;
                q.push(there);
                cache[there.k][there.r][there.c] = cache[here.k][here.r][here.c] + 1;
            }
        }

    }

    if(ans == 987654321)
        cout << -1;
    else
        cout << ans;

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
