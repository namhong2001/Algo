#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int get_team_num(vector<string> &teams, string &team) {
    for (int i=0; i<teams.size(); ++i) {
        if (teams[i] == team) return i;
    }
}

void update_chances(vector<vector<string>> &cases, vector<double> &next_round_chances) {
    bool complete = true;
    for (int i=0; i<4; ++i) {
        for (int j=0; j<4; ++j) {
            if (cases[i][j].empty() && i != j) {
                vector<vector<string>> new_cases1(cases);
                new_cases1[i][j] = "w";
                new_cases1[j][i] = "l";
                update_chances(new_cases1, next_round_chances);
                vector<vector<string>> new_cases2(cases);
                new_cases2[i][j] = "d";
                new_cases2[j][i] = "d";
                update_chances(new_cases2, next_round_chances);
                vector<vector<string>> new_cases3(cases);
                new_cases3[i][j] = "l";
                new_cases3[j][i] = "w";
                update_chances(new_cases3, next_round_chances);
                complete = false;
            }
        }
    }
    if (complete) {
        for (int i=0; i<4; ++i) {
            for (int j=i+1; j<4; ++j) {
                if (cases[i][j] == "w") {

                } else if (cases[i][j] == "d") {

                } else if (cases[i][j] == "l") {

                }
            }
        }
    }
}

int main() {
    vector<string> teams;
    string team;
    for (int i=0; i<4; ++i) {
        cin >> team;
        teams.push_back(team);
    }

    double chance[4][4][3];
    for (int i=0; i<6; ++i) {
        string team1, team2;
        double win, draw, lose;
        cin >> team1 >> team2 >> win >>  draw >> lose;
        int team1_num = get_team_num(teams, team1);
        int team2_num = get_team_num(teams, team2);
        chance[team1][team2][0] = win;
        chance[team1][team2][1] = draw;
        chance[team1][team2][2] = lose;
        chance[team2][team1][0] = lose;
        chance[team2][team1][1] = draw;
        chance[team2][team1][2] = win;
    }
    vector<double> next_round_chance(4);
    vector<string> cases(6); // bcd cd d
    for





    return 0;
}
