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

int T;
int M, N, K;
int adj[51][51];
int visited[51][51];
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
vector<pii> bc;
void dfs(int y, int x) {
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
			if (!visited[ny][nx] && (adj[ny][nx] == 1)) {
				dfs(ny, nx);
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	for (int Case = 0; Case < T; Case++) {
		cin >> M >> N >> K;
		int ret = 0;
		memset(visited, 0, sizeof(visited));
		memset(adj, 0, sizeof(adj));
		bc.clear();
		for (int i = 0; i < K; i++) {
			int a, b;
			cin >> a >> b;
			adj[b][a] = 1;
			bc.push_back({ b,a });
		}
		for (int i = 0; i < bc.size(); i++) {
			int y = bc[i].first;
			int x = bc[i].second;
			if (!visited[y][x]){
				dfs(y, x);
				ret++;
			}
		}

		cout <<ret << "\n";

	}

	
	return 0;
}

