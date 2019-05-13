#include <iostream>
#include <queue>
#include <deque>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class fall {
public:
    fall(int time, int id): time(time), id(id) {}
    int time;
    int id;
};

class ant {
public:
    ant(int id, int pos, int used_time, int direction): id(id), pos(pos), used_time(used_time), direction(direction) {}
    int id;
    int pos;
    int used_time;
    int direction;
};

class facing {
public:
    facing(int time, deque<ant>::iterator it_1, deque<ant>::iterator it_2): time(time), it_1(it_1), it_2(it_2) {}
    int time;
    deque<ant>::iterator it_1;
    deque<ant>::iterator it_2;
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, l, k;
        cin >> n >> l >> k;
        l *= 2;
        deque<ant> lane;
        queue<fall> left;
        queue<fall> right;
        auto cmp = [](const facing &a, const facing &b) { return a.time < a.time; };
        priority_queue<facing, vector<facing>, decltype(cmp)> encounter(cmp);
        int elapsed_time = 0;
        while (n--) {
            int p, a;
            cin >> p >> a;
            if (lane.empty() && a<0) {
                left.push(fall(2*p, a));
            } else {
                lane.push_back(ant(a, 2*p, 0, a<0 ? -1 : 1));
            }
        }
        for (auto it=lane.rbegin(); it!=lane.rend() && it->direction>0; ++it) {
            right.push(fall(l-it->pos, it->id));
            lane.pop_back();
        }
        for (auto it = lane.begin(); it!=lane.end(); ++it) {
            if (it+1 == lane.end()) break;
            if (it->direction > 0 && (it+1)->direction < 0) {
                int time = ((it+1)->pos - it->pos)/2;
                encounter.push(facing(time, it, it+1));
            }
        }

        while(!lane.empty()) {
            facing top = encounter.top();
            encounter.pop();
            elapsed_time = top.time;
            auto &it_1 = top.it_1;
            auto &it_2 = top.it_2;

//            cout << lane.size() << ' ' << encounter.size() << endl;
//            cout << "front id: " << lane.front().id << endl;
//            cout << "front direction: " << lane.front().direction << endl;
//            cout << "back id: " << lane.back().id << endl;
//            cout << "(lane.begin() == it_1) ? " << (lane.begin() == it_1) << endl;
//            cout << "(lane.end()-1 == it_2) ? " << (lane.end()-1 == it_2) << endl;
//            cout << "it_1->id " << it_1->id << endl;
//            cout << "it_2->id " << it_2->id << endl;

            it_1->pos += it_1->direction * (elapsed_time - it_1->used_time);
            it_1->used_time = elapsed_time;
            it_1->direction *= -1;

            it_2->pos += it_2->direction * (elapsed_time - it_2->used_time);
            it_2->used_time = elapsed_time;
            it_2->direction *= -1;

            if (lane.begin() == it_1) {
                int time = it_1->pos + elapsed_time;
                left.push(fall(time, it_1->id));
                lane.pop_front();
            } else if ((it_1-1)->direction > 0) {
                auto it_left = it_1-1;

                it_left->pos += it_left->direction * (elapsed_time - it_left->used_time);
                it_left->used_time = elapsed_time;

                int time = elapsed_time + (it_1->pos - it_left->pos)/2;
                encounter.push(facing(time, it_left, it_1));
            }
            if (lane.end()-1 == it_2) {
                int time = l - it_2->pos + elapsed_time;
                right.push(fall(time, it_2->id));
                lane.pop_back();
            } else if ((it_2+1)->direction < 0) {
                auto it_right = it_2+1;

                it_right->pos += it_right->direction * (elapsed_time - it_right->used_time);
                it_right->used_time = elapsed_time;

                int time = elapsed_time + (it_right->pos - it_2->pos)/2;
                encounter.push(facing(time, it_2, it_right));
            }
        }

        auto fall_comp = [](const fall &a, const fall &b) {
            if (a.time == b.time) {
                return a.id > b.id;
            } else {
                return a.time > b.time;
            }
        };

        priority_queue<fall, vector<fall>, decltype(fall_comp)> result(fall_comp);
        while(!left.empty()) {
            result.push(left.front());
            left.pop();
        }
        while(!right.empty()) {
            result.push(right.front());
            right.pop();
        }
        int cnt = 1;
        while (!result.empty()) {
            if (cnt == k) {
                cout << result.top().id << endl;
                break;
            }
//            cout << result.top().id << ' ' << result.top().time << endl;

            ++cnt;
            result.pop();
        }
    }

    return 0;
}
