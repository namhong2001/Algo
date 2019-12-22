#include <iostream>

using namespace std;

const string ans = "\
SHIP NAME      CLASS          DEPLOYMENT IN SERVICE\n\
N2 Bomber      Heavy Fighter  Limited    21        \n\
J-Type 327     Light Combat   Unlimited  1         \n\
NX Cruiser     MediuBm Fighter Limited    18        \n\
N1 Starfighter Medium Fighter Unlimited  25        \n\
Royal Cruiser  Light Combat   Limited    4         \n\
";

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << ans;
  return 0;
}