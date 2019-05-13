#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <functional>


using namespace std;

struct Circle {
    int x;
    int y;
    int r;
    int height = 0;
    Circle* parent;
    vector<Circle*> children;

    int getHeight() {
        if (height > 0) return height;
        if (children.empty()) return 0;

        for (int i=0; i<children.size(); ++i) {
            height = max(height, children[i]->getHeight()+1);
        }
        return height;
    }
};


bool isIn(const Circle* a, const Circle* b) {
    int dist = pow(abs(a->x - b->x), 2) + pow(abs(a->y - b->y), 2);
    return pow(a->r, 2) > dist;
}

Circle* makeTree(Circle* root, const vector<Circle*> &circles) {
    vector<Circle*> children;
    vector<vector<Circle*>> descendants;
    for (int i=0; i<circles.size(); ++i) {
        Circle* target = circles[i];
        bool inserted = false;
        for (int j=0; j<children.size(); ++j) {
            if (isIn(children[j], target)) {
                descendants[j].push_back(target);
                inserted = true;
                break;
            }
        }
        if (!inserted) {
            target->parent = root;
            children.push_back(target);
            descendants.push_back({}); // check necessary
        }
    }
    root->children = children;
    for (int i=0; i<children.size(); ++i) {
        makeTree(children[i], descendants[i]);
    }
    return root;
}

int solve(Circle* root) {
    vector<Circle*> &children = root->children;

    int ans = 0;
    vector<int> heights;
    for (int i=0; i<children.size(); ++i) {
        ans = max(ans, solve(children[i]));
        heights.push_back(children[i]->getHeight());
    }
    sort(heights.begin(), heights.end(), greater<int>());
    if (heights.size() >= 2) {
        ans = max(ans, heights[0] + heights[1] + 2);
    } else if (heights.size() == 1) {
        ans = max(ans, heights[0]+1);
    }

    return ans;
}



int main() {
    int c;
    cin >> c;
    while (c--) {
        int n;
        cin >> n;
        vector<Circle*> circles;
        for (int i=0; i<n; ++i) {
            Circle* circle = new Circle();
            cin >> circle->x >> circle->y >> circle->r;
            circles.push_back(circle);
        }
        sort(circles.begin(), circles.end(), [](const Circle* A, const Circle* B){return A->r > B->r;});
        Circle* root = makeTree(circles.front(), vector<Circle*>(circles.begin()+1, circles.end()));
        cout << solve(root) << endl;
    }
}
