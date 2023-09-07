#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <functional>
#include <map>
#include <set>
#include <sstream>
#include <stack>
#include <queue>
using namespace std;
#define INF 987654321
#define LINF 321321321321
#define MOD 9901
typedef long long ll;

int n, k;
int coin[101];
int dp[100001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;

	memset(dp, 98765432, sizeof(dp));
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
		dp[coin[i]] = 1;
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < n; j++) {
			if (i - coin[j] > 0) {
				if (dp[i - coin[j] != INF]) {
					dp[i] = min(dp[i],dp[i - coin[j]] + 1);
				}
			}
		}
	}
	
	
	if (dp[k] >= INF)
		cout << -1;
	else
		cout << dp[k];
	
	return 0;
}



