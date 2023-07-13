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

vector<int> v[101];
int N;

int visited[101];
int ret = -1;
bool chk() {

	for (int i = 1; i <= N; i++) {
		if (!visited[i])
			return false;
	}
	return true;
}

void dfs(int cur) {

	
	if(!visited[cur])
		visited[cur] = 1;

	if (chk()) {
		ret = 1;
		return;
	}

	for (int i = 0; i < v[cur].size(); i++) {
		int next = v[cur][i];
		if (!visited[next]) {
			dfs(next);
		}
	}

	return;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N-1; i++) {
		int a, b;
		cin >> a >> b;
		v[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		memset(visited, 0, sizeof(visited));
		dfs(i);
		if (ret != -1) {
			cout << i;
			return 0;
		}
	}
	cout << -1;
	return 0;
}

