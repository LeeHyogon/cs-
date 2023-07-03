#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
#define INF 987654321
#define LINF 321321321321

int N,T;
int star[100001][2];
int dp[100001][2];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	vector<int> ret;
	for (int a = 0; a < T; a++) {
		memset(dp, 0, sizeof(dp));
		cin >> N;

		for (int i = 0; i <N; i++) {
			cin >> star[i][0];
		}
		for (int i = 0; i <N; i++) {
			cin >> star[i][1];
		}
		dp[0][0] = star[0][0];
		dp[0][1] = star[0][1];
		for (int i = 1; i < N; i++) {
			if (i == 1) {
				dp[i][1] = dp[i - 1][0] + star[i][1];
				dp[i][0] = dp[i - 1][1] + star[i][0];
				continue;
			}
			dp[i][1] = max(dp[i - 1][0] + star[i][1],dp[i-2][0]+star[i][1]);
			dp[i][0] = max(dp[i - 1][1] + star[i][0], dp[i - 2][1] + star[i][0]);
		}
		ret.push_back( max(dp[N - 1][0], dp[N - 1][1]));
	}
	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i] << "\n";
	}
	
	return 0;
}

