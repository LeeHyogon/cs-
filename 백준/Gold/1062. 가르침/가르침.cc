#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<string>
#include<tuple>
#include<cmath>
#include<functional>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define INF 987654321
#define LINF 321321321321
#define MAX 100

int N, K;
char a[6] = "antic";
char b[22] = "bdefghjklmopqrsuvwxyz";
int str[100];
int v[100];
string s;
int ans;
void stob(int index) {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'a' || s[i] == 'n' || s[i] == 't' || s[i] == 'i' || s[i] == 'c') continue;
		for (int j = 0; j < 21; j++) {
			if (s[i] == b[j]) {
				str[index] |= 1 << j;
			}
		}
	}
}

void picked(int cnt, int depth) {
	
	if (depth >= 22) return;
	if (cnt == K - 5) {
		int ret = 0;
		int tmp = 0;
		for (int i = 0; i < cnt; i++) {
			tmp |= 1 << v[i];
		}
		for (int i = 0; i < N; i++) {
			if (str[i] == (str[i] & tmp))
				ret++;
		}

		ans = max(ans, ret);
		return;
	}
	v[cnt] = depth;
	picked(cnt + 1, depth + 1);
	v[cnt] = 0;
	picked(cnt, depth + 1);

}


int main(void) {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> s;
		stob(i);
	}
	if (K - 5 < 0) {
		cout << 0;
		return 0;
	}
	
	picked(0, 0);
	cout << ans;
	
	return 0;

}