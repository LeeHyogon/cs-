#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<functional>
#include<cstdbool>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define INF 987654321
#define LINF 321321321321
#define MAX 1100
int n, m;
int board[1001][1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;


	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= s.size(); j++) {
			board[i][j] = s[j-1] - '0';
			
		}
	}
	int ans = 0;
	for (int i = 1; i <=n; i++) {

		for (int j = 1; j <= m; j++) {
			if (board[i][j]) {
				board[i][j] = min(min(board[i - 1][j], board[i][j - 1]), board[i - 1][j - 1]) + 1;
				ans= max(ans, board[i][j]);
			}
		}
	}
	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	*/

	cout << ans*ans;
	
	return 0;
}