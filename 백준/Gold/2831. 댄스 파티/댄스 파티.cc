#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
#define INF 987654321
#define LINF 321321321321
typedef long long ll;
typedef pair<int, int > pii;

//남자 N명 여자 N명 
// 1500<=키<=2500
// -2500<=키<=-1500
// 양수 -> 자기보다 큰사람
// 음수 -> 자기보다 작은사람
// 키가 같은 경우는 일어나지 않음
int N;
vector<int> man_minus;
vector<int> man_plus;
vector<int> girl_minus;
vector<int> girl_plus;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	int a;
	for (int i = 0; i < N; i++) {
		cin >> a;
		if (a < 0)
			man_minus.push_back(-a);
		else
			man_plus.push_back(a);
	}
	for (int i = 0; i < N; i++) {
		cin >> a;
		if (a < 0)
			girl_minus.push_back(-a);
		else
			girl_plus.push_back(a);
	}
	if(!man_plus.empty())
		sort(man_plus.begin(), man_plus.end());
	if (!girl_plus.empty())
		sort(girl_plus.begin(), girl_plus.end());
	if (!man_minus.empty())
		sort(man_minus.begin(), man_minus.end());
	if(!girl_minus.empty())
		sort(girl_minus.begin(), girl_minus.end());
	int ret = 0;
	int gp_pos = 0; int mm_pos = 0;
	while (1) {
		if (mm_pos >= man_minus.size() || man_minus.empty())
			break;
		if (gp_pos >= girl_plus.size() || girl_plus.empty())
			break;
		if (man_minus[mm_pos] > girl_plus[gp_pos]) {
			ret++; 
			gp_pos++;
		}
		mm_pos++;
	}
	int gm_pos = 0; int mp_pos = 0;
	while (1) {
		if (mp_pos >= man_plus.size() || man_plus.empty())
			break;
		if (gm_pos >= girl_minus.size() || girl_minus.empty())
			break;
		if (girl_minus[gm_pos] > man_plus[mp_pos]) {
			ret++; mp_pos++;
		}
		gm_pos++;
	}

	cout << ret;
	return 0;
}

