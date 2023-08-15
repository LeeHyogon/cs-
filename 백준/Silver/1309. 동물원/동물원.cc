#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <functional>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <stack>
#include <queue>
using namespace std;
#define INF 987654321
#define LINF 321321321321
#define MOD 9901
int N;
int dp[100001][3];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	dp[0][0] = 1;
	dp[0][1] = 1;
	dp[0][2] = 1;

	for (int i = 1; i < N; i++) {
		dp[i][0] = dp[i - 1][1] + dp[i - 1][2]%MOD;
		dp[i][1] = dp[i - 1][0] + dp[i - 1][2] % MOD;
		dp[i][2] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] % MOD;
	}

	cout << (dp[N - 1][0] + dp[N - 1][1] + dp[N - 1][2]) % MOD;

	return 0;
}

