#include <iostream>

using namespace std;

const int FIELD_SIZE = 20;
char field[FIELD_SIZE][FIELD_SIZE];

int shape[4][2][2] = {
    {{0, 1}, {1, 1}},
    {{0, 1}, {1, 0}},
    {{1, 0}, {1, -1}},
    {{1, 0}, {1, 1}}
};



int cover(int h, int w, int h_max, int w_max) {
    int x = -1, y = -1;
    bool catched = false;
    for (int i=h; i<h_max; ++i) {
        for (int j=w; j<w_max; ++j) {
            if (field[i][j] == '.') {
                x = i;
                y = j;
                catched = true;
                break;
            }
        }
        if (catched) break;
        w = 0;
    }
    if (!catched) {
//        for (int i=0; i<h_max; ++i) {
//            for (int j=0; j<w_max; ++j) {
//                cout << field[i][j];
//            }
//            cout << endl;
//        }
//        cout << "++count" << endl;
        return 1;
    }

    int ret = 0;
    for (int i=0; i<4; ++i) {
        int block_1_x = x+shape[i][0][0];
        int block_1_y = y+shape[i][0][1];
        if (block_1_x < 0 || block_1_x >= h_max || block_1_y < 0 || block_1_y >= w_max) {
            continue;
        }
        char &block_1 = field[block_1_x][block_1_y];

        int block_2_x = x+shape[i][1][0];
        int block_2_y = y+shape[i][1][1];
        if (block_2_x < 0 || block_2_x >= h_max || block_2_y < 0 || block_2_y >= w_max) {
            continue;
        }
        char &block_2 = field[block_2_x][block_2_y];

        if (block_1 == '.' && block_2 == '.') {

//            cout << x << ' ' << y << endl;
            field[x][y] ='#';
            block_1 = '#';
            block_2 = '#';

            ret += cover(x, y, h_max, w_max);

            field[x][y] ='.';
            block_1 = '.';
            block_2 = '.';
        }
    }
    return ret;
}


int main() {
    int c;
    cin >> c;
    while (c--) {
        int h, w;
        cin >> h >> w;
        for (int i=0; i<h; ++i) {
            for (int j=0; j<w; ++j) {
                cin >> field[i][j];
            }
        }
        cout << cover(0, 0, h, w) << endl;
    }

    return 0;
}
