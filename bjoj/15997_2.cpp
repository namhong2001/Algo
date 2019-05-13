#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int get_team_num(vector<string> &teams, string &team) {
    for (int i=0; i<teams.size(); ++i) {
        if (teams[i] == team) return i;
    }
}

int main() {
    vector<string> teams;
    string team;
    for (int i=0; i<4; ++i) {
        cin >> team;
        teams.push_back(team);
    }

    double chance[4][4][3] = {0.0};
    for (int i=0; i<6; ++i) {
        string team1, team2;
        double win, draw, lose;
        cin >> team1 >> team2 >> win >>  draw >> lose;
        int team1_num = get_team_num(teams, team1);
        int team2_num = get_team_num(teams, team2);
        chance[team1_num][team2_num][0] = win;
        chance[team1_num][team2_num][1] = draw;
        chance[team1_num][team2_num][2] = lose;
        chance[team2_num][team1_num][0] = lose;
        chance[team2_num][team1_num][1] = draw;
        chance[team2_num][team1_num][2] = win;
    }
    double score[4] = {0.0};
    for (int i=0; i<4; ++i) {
        for (int j=0; j<4; ++j) {
            score[i] += chance[i][j][0] * 3;
            score[i] += chance[i][j][1] * 1;
        }
    }

    double next_round[4];
    for (int i=0; i<4; ++i) {
        next_round[i] = -1;
    }
    double sum = 0;
    for (int i=0; i<4; ++i) {
        sum += score[i];
    }
    int candidate = 4;
    int ticket = 2;
    for (int i=0; i<4; ++i) {
        if (score[i] == 0) {
            next_round[i] = 0;
            candidate--;
        } else if (score[i] >= 6) {
            next_round[i] = 1;
            sum -= score[i];
            ticket--;
        }
    }
    for (int i=0; i<4; ++i) {
        if (next_round[i] >= 0) continue;
        if (ticket == 0) next_round[i] = 0;
        else if (candidate == ticket) next_round[i] = 1;
        else next_round[i] = score[i]/sum * ticket;
    }
    for (auto result : next_round) {
        cout << fixed << setprecision(10) << result << '\n';
    }

    return 0;
}
