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
#define MAX 101

int n, m;
//현재 이 인덱스에서 이 cost를 사용하는 최대 메모리값
int cache[101][10010];
int M[MAX];
int c[MAX];
int visited[MAX];
int dfs(int index, int cost) {
	
	if (index >= n)
		return 0;

	int &ret = cache[index][cost];

	if (ret != -1)
		return ret;

	ret = dfs(index + 1, cost);

	if (c[index] <= cost) {
		ret = max(ret, dfs(index + 1, cost - c[index])+M[index]);
	}

	return ret;
}



int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> M[i];

	for (int i = 0; i < n; i++)
		cin >> c[i];

	memset(cache, -1, sizeof(cache));
	
	for (int i = 0;; i++) {
		if (dfs(0, i)>=m) {
			cout << i;
			return 0;
		}
	}
	


	return 0;
}