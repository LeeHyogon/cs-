#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
#define INF 987654321
#define LINF 321321321321
int N;
int board[20][20];
int visited[20][20];

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };
int ret = 0;
struct Path {
	int dist, y, x;

	bool operator<(const Path& rhs) const
	{
		if (dist != rhs.dist)
			return dist > rhs.dist;
		if (y != rhs.y)
			return y < rhs.y;
		return x < rhs.x;
	}
};


Path bfs(int sy,int sx,int ssize) {

	memset(visited, 0, sizeof(visited));
	
	priority_queue<Path> pq;
	Path p = { INF,INF,INF };
	visited[sy][sx] = 1;
	pq.push({ 0,sy,sx });
	while (!pq.empty()) {
		int dist = pq.top().dist;
		int y = pq.top().y;
		int x = pq.top().x;
		pq.pop();

		for (int dir = 0; dir < 4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (ny < 0 || ny >= N || nx < 0 || nx >= N)
				continue;
			if (board[ny][nx] > ssize)
				continue;
			if (!visited[ny][nx]) {
				visited[ny][nx] = dist + 1;
				pq.push({ dist + 1,ny,nx });
				if (board[ny][nx] && board[ny][nx]<ssize) {
					if (p.dist >=dist + 1) {
						if (p.dist == dist + 1) {
							if (p.y > ny)
								p = { dist + 1,ny,nx };
							else if (p.y == ny) {
								if(p.x>nx)
									p = { dist + 1,ny,nx };
							}
						}
						else if (p.dist > dist + 1) {
							p = { dist + 1,ny,nx };
						}
					}
				}
			}
		}
	}
	return p;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	int sy, sx;
	int ssize = 2;
	int ecnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 9) {
				sy = i; sx = j;
			}
		}
	}
	board[sy][sx] = 0;
	while (1) {
		Path p = bfs(sy, sx, ssize);
		if (p.dist == INF) {
			cout << ret;
			return 0;
		}
		ret += p.dist;
		sy = p.y;
		sx = p.x;
		board[sy][sx] = 0;
		ecnt++;
		if (ssize == ecnt) {
			ssize++; ecnt = 0;
		}

	}

	return 0;
}

