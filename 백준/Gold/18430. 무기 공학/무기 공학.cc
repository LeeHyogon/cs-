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

int N, M;

int board[6][6];
int visited[6][6];
vector<pii> pos;
int ret = 0;
bool chk(int y, int x, int dir) {
	if (dir == 1) {
		if (x - 1 >= 0 && y + 1 < N) {
			if (!visited[y][x - 1] && !visited[y][x] && !visited[y + 1][x])
				return true;
		}
	}
	if (dir == 2) {
		if (y - 1 >= 0 && x-1 >=0 ) {
			if (!visited[y][x - 1] && !visited[y][x] && !visited[y-1][x])
				return true;
		}
	}
	if (dir == 3) {
		if (y - 1 >= 0 && x + 1 < M) {
			if (!visited[y-1][x] && !visited[y][x] && !visited[y][x+1])
				return true;
		}
	}
	if (dir == 4) {
		if (y +1 < N && x + 1 < M) {
			if (!visited[y][x] && !visited[y+1][x] && !visited[y][x + 1])
				return true;
		}
	}
	return false;
}

int Insert(int y, int x, int dir) {
	if (dir == 1) {
		visited[y][x - 1] = 1;
		visited[y][x] = 1;
		visited[y + 1][x] = 1;
		return board[y][x - 1] + board[y][x]*2 + board[y + 1][x];
	}
	if (dir == 2) {
		visited[y - 1][x] = 1;
		visited[y][x] = 1;
		visited[y][x - 1] = 1;
		return board[y - 1][x] + board[y][x] * 2 + board[y][x - 1];
	}
	if (dir == 3) {
		visited[y - 1][x] = 1;
		visited[y][x] = 1;
		visited[y][x + 1] = 1;
		return board[y - 1][x] + board[y][x] * 2 + board[y][x + 1];

	}
	if (dir == 4) {
		visited[y + 1][x] = 1;
		visited[y][x] = 1;
		visited[y][x + 1] = 1;
		return board[y + 1][x] + board[y][x] * 2 + board[y][x + 1];
	}
}
void Delete(int y, int x, int dir) {
	if (dir == 1) {
		visited[y][x - 1] = 0;
		visited[y][x] = 0;
		visited[y + 1][x] = 0;
	}
	if (dir == 2) {
		visited[y - 1][x] = 0;
		visited[y][x] = 0;
		visited[y][x - 1] = 0;
	}
	if (dir == 3) {
		visited[y - 1][x] = 0;
		visited[y][x] = 0;
		visited[y][x + 1] = 0;
	}
	if (dir == 4) {
		visited[y][x] = 0;
		visited[y + 1][x] = 0;
		visited[y][x + 1] = 0;
	}
}

void DFS(int cur, int val) {


	if (cur == pos.size()) {
		ret = max(ret, val);
		return;
	}

	for (int dir = 1; dir <= 4; dir++) {
		int cy = pos[cur].first;
		int cx = pos[cur].second;
		if (chk(cy, cx, dir)) {
			int tmp = Insert(cy, cx, dir);
			DFS(cur + 1, val + tmp);
			Delete(cy, cx, dir);
		}
	}
	DFS(cur + 1, val);
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			pos.push_back({ i,j });
		}
	}
	DFS(0, 0);
	cout << ret;

	return 0;
}

