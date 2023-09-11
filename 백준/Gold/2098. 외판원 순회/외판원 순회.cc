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
int cache[MAX][1<<MAX];

int dp(int here, int visited) {

	if (visited == ( (1 << n ) - 1)) {
		if (!W[here][0])
			return INF;
		else
			return W[here][0];
	}
	int &ret = cache[here][visited];

	if (ret != -1)
		return ret;

	ret = INF;

	for (int i = 0; i < n; i++) {
		if (W[here][i] && ( (visited& (1<<i)) == 0)) {
			ret = min(ret, dp(i, visited | (1<<i)) + W[here][i]);
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
	cout << dp(0, 1);

	
	return 0;
}