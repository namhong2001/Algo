#include <iostream>
#include <algorithm>


using namespace std;

const int N_MAX = 1000;

int dp_red[N_MAX+1] = {0};
int dp_green[N_MAX+1] = {0};
int dp_blue[N_MAX+1] = {0};
int cost_red[N_MAX+1] = {0};
int cost_green[N_MAX+1] = {0};
int cost_blue[N_MAX+1] = {0};


int total_cost(int n, string color) {
    if (n < 0) return 0;
    if (n == 0) {
        if (color == "red") return cost_red[0];
        else if (color == "blue") return cost_blue[0];
        else if (color == "green") return cost_green[0];
    }
    if (color == "red") {
        if (dp_red[n] > 0) return dp_red[n];
        else {
            dp_red[n] = min(total_cost(n-1, "blue"), total_cost(n-1, "green")) + cost_red[n];
            return dp_red[n];
        }
    } else if (color == "blue") {
        if (dp_blue[n] > 0) return dp_blue[n];
        else {
            dp_blue[n] = min(total_cost(n-1, "red"), total_cost(n-1, "green")) + cost_blue[n];
            return dp_blue[n];
        }
    } else if (color == "green") {
        if (dp_green[n] > 0) return dp_green[n];
        else {
            dp_green[n] = min(total_cost(n-1, "red"), total_cost(n-1, "blue")) + cost_green[n];
            return dp_green[n];
        }
    }
}

int main() {

    int n;
    cin >> n;
    for (int i=0; i<n; ++i) {
        int red, green, blue;
        cin >> red >> green >> blue;
        cost_red[i] = red;
        cost_green[i] = green;
        cost_blue[i] = blue;
    }
    cout << min(min(total_cost(n, "red"), total_cost(n, "blue")), total_cost(n, "green"));
    return 0;
}
