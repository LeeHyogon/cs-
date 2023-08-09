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

int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
int n, m;
int board[1001][1001];
int dp[1001][1001];
int visited[1001][1001];
int ans[1001][1001];
int sy, sx;
struct Path
{
	int dist, y, x;
	bool operator<(const Path &d)const {
		return dist < d.dist;
	}
};

void bfs() {

	queue<Path> pq;
	pq.push({ 0,sy,sx });
	while (!pq.empty()) {
		int dist = pq.front().dist;
		int y = pq.front().y;
		int x = pq.front().x;
		pq.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && ny < n && nx >= 0 && nx < m && board[ny][nx] == 1) {
				if (!ans[ny][nx]) {
					pq.push({ dist + 1,ny,nx });
					ans[ny][nx] = dist + 1;
				}
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) {
				sy = i;
				sx = j;
			}
		}
	}
	bfs();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 1 && ans[i][j] == 0)
				cout << -1 << " ";
			else
				cout << ans[i][j] << " ";
		}
		cout << "\n";
	}


	return 0;
}

