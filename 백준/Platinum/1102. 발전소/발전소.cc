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
#define MAX 16
int n;
int W[MAX][MAX];
int cache[1<<MAX];
int P;
int dp(int visited,int cnt) {

	if (cnt >= P)
		return 0;
	
	int &ret = cache[visited];
	if (ret != -1)
		return ret;

	ret = INF;

	for (int here = 0; here < n; here++) {
		if (visited == (visited | (1 << here))) {
			for (int next = 0; next < n; next++) {
				if (visited != (visited | (1 << next))) {
					ret = min(ret, dp((visited | (1 << next)), cnt + 1)+W[here][next]);
				}
			}
		}
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> W[i][j];
	
	memset(cache, -1, sizeof(cache));
	int visited = 0;

	string s;
	cin >> s;
	cin >> P;
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'Y') {
			visited = (visited | (1 << i));
			cnt++;
		}
	}
	int ans=dp(visited, cnt);
	if (ans >= INF)
		cout << -1;
	else
		cout << ans;


	return 0;
}