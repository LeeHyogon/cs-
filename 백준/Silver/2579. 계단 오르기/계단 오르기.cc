#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
#define INF 987654321
#define LINF 321321321321

int N;
int dp[301];
int stairs[301];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> stairs[i];
	if (N == 1) {
		cout << stairs[1];
		return 0;
	}
	else if (N == 2) {
		cout << stairs[1] + stairs[2];
		return 0;
	}
	dp[1] = stairs[1];
	dp[2] = stairs[1]+stairs[2];
	for (int i = 3; i <= N; i++) {
		dp[i] = max(dp[i - 3] + stairs[i - 1] + stairs[i], dp[i - 2] + stairs[i]);
	}
	cout << dp[N];
	return 0;
}

