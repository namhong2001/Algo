#include <iostream>

#include <string.h>

#include <algorithm>

#define INF 987654321

#pragma warning(disable:4996)

using namespace std;



// ans : the minimum semester to graduate from

// if it's impossible, print IMPOSSIBLE



int n, k, m, l;

int pre_condition[12];

int semester[10];

int dp[10][(1 << 12)];



void init() {

	memset(pre_condition, 0, sizeof(pre_condition));

	memset(semester, 0, sizeof(semester));

	memset(dp, -1, sizeof(dp));

}



int bitCount(int target) {

	int ret = 0;

	int checkBit;

	for (int i = 0; i < 12; i++) {

		checkBit = (1 << i);

		if ((checkBit & target) == 0) continue;

		ret++;

	}

	return ret;

}



// 현재 num 학기고, 지금까지 들은게 taken이면

// 졸업할 수 있는 최소 학기 수는?

int graduate(int num, int taken) {

	if (bitCount(taken) >= k) return 0;

	if (num == m) return INF;

	

	int& ret = dp[num][taken];

	if (ret != -1) return ret;

	ret = INF;

	// 지금 내가 들을 수 있는 수업을 모두 찾음

	int possibility = (semester[num] & ~taken);

	// 선수 과목 때문에 들을 수 없는 과목을 걸러낸다

	for (int i = 0; i < n; i++) {

		if ((possibility & (1 << i)) && ((taken & pre_condition[i]) != pre_condition[i])) {

			possibility &= ~(1 << i);

		}

	}

	// 자 그럼 위에서 뺀 나머지 모든 과목들을 전부 돌아보자

	//a &= (a - 1);

	for (int take = possibility; take > 0;

		take = ((take - 1) & possibility)) {

		if (bitCount(take) > l) continue;

		// 학기가 하나 지나가는 거니깐, 후자는 + 1을 하자. 

		// 이 때, 다음 학기를 계산 하는건 take를 넣어주자

		// 이렇게 하면 1이 많은 애부터 자동으로 넣게 되니깐...

		ret = min(ret, graduate(num + 1, taken | take) + 1);

	}

	// 이건 이번 학기에 아무것도 안들었을때니까

	// 후자에 + 1을 굳이 안해줘도 된다. 어차피 휴학이니까.

	ret = min(ret, graduate(num + 1, taken));

	return ret;

}



int main(void) {

	int c;

	cin >> c;

	for (int tc = 0; tc < c; tc++) {

		bool is_end = false;

		cin >> n >> k >> m >> l;

		init();

		

		for (int i = 0; i < n; i++) {

			int temp;

			cin >> temp;

			for (int j = 0; j < temp; j++) {

				int pos;

				cin >> pos;

				pre_condition[i] |= (1 << pos);

			}

		}

		

		for (int i = 0; i < m; i++) {

			int temp;

			cin >> temp;

			for (int j = 0; j < temp; j++) {

				int pos;

				cin >> pos;

				semester[i] |= (1 << pos);

			}

		}

		

		// 생각해보니 이거 최소임.. 그 말은 즉 최적화를 해야 한다는거

		// DP를 사용하는 방법도 존재할 것

		// dp[semeseter][choice_subject] ->  이번 학기에 내가 고른 과목들을 이수했을 때 총 이수한 과목 수

		int ans = graduate(0, 0);

		if (ans >= INF) cout << "IMPOSSIBLE" << endl;

		else cout << ans << endl;



		// 밑에 있는 코드는 단순히 각 학기마다 모두 도는 방법

		// 답을 찾을순 있겠지만, 늘 최소인 답을 주진 못할 것임.

		//for (current = 1; current <= m; current++) {

		//	int subject_cnt = 0;

		//	// 내가 안들었고, 선수 과목을 다 들었고, 이번 학기에 들을 수 있을 것

		//	for (int sub_num = 0; sub_num < n; sub_num++) {

		//		if (subject_cnt >= l) break;

		//		if (!(myStatus & (1 << sub_num)) 

		//			&& (((myStatus & pre_condition[sub_num]) == pre_condition[sub_num]) || (!pre_condition[sub_num])) 

		//			&& ((1 << sub_num) & semester[current - 1])) {

		//			addSubject |= (1 << sub_num);

		//			subject_cnt++;

		//		}

		//	}

		//	if (!subject_cnt) rest_semester++;

		//	myStatus |= addSubject;

		//	addSubject = 0;

		//	if (check_end(myStatus, k)) {

		//		is_end = true;

		//		cout << current - rest_semester << endl;

		//		break;

		//	}

		//}

		//if (!is_end) {

		//	if(check_end(myStatus,k)) cout << current - rest_semester << endl;

		//	else cout << "IMPOSSIBLE" << endl;

		//}

	}

	return 0;

}


