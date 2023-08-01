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
typedef long long ll;
typedef pair<int, int > pii;

int n;
int dp[1000001];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	memset(dp, -1, sizeof(dp));

	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		if (!(i % 3)) dp[i] = min(dp[i], dp[i / 3] + 1);
		if (!(i % 2)) dp[i] = min(dp[i], dp[i / 2] + 1);
	}

	cout << dp[n];

	return 0;
}

