#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
#define INF 987654321
#define LINF 321321321321

int n, k;
int ret = 0;

int str[101];
int v[101];
string alpha = "bdefghjklmopqrsuvwxyz";

void stob(string s, int index) {
	int tmp = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'a' || s[i] == 'n' || s[i] == 't' || s[i] == 'i' || s[i] == 'c')
			continue;
		for (int j = 0; j < 21; j++) {
			if (s[i] == alpha[j]) {
				tmp |= 1 << j;
			}
		}
	}
	str[index] = tmp;
}

void dfs(int cnt, int cur) {

	if (cur >= 22)
		return;
	if (cnt == k - 5) {

		int tmp = 0;
		for (int i = 0; i < cnt; i++) {
			tmp |= (1 << v[i]);
		}
		int tcnt = 0;
		for (int i = 0; i < n; i++) {
			if (str[i] == (str[i] & tmp)) {
				tcnt++;
			}
		}
		ret = max(ret, tcnt);
		return;
	}
	v[cnt] = cur;
	dfs(cnt+1, cur + 1);
	v[cnt] = 0;
	dfs(cnt, cur + 1);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		stob(s, i);
	}
	if (k - 5 < 0) {
		cout << 0;
		return 0;
	}
	dfs(0,0);
	cout << ret;
	return 0;
}

