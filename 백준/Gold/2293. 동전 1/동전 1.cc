#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
#define INF 987654321
#define LINF 321321321321

int n, k;
int coin[10001];
int dp[100001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> coin[i];
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int v = 1; v <= k; v++) {
			if (v - coin[i] >= 0) {
				dp[v] += dp[v - coin[i]];
			}
		}
	}
	
	cout << dp[k];
	
	return 0;
}

