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

int visited[6][6];
int R, C, K;
int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };
vector<string> road;

int ret = 0;
void dfs(int y, int x,int dist) {

	if (y == 0 && x == C - 1) {
		if (dist == K) {
			ret++;
			return;
		}
	}



	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny >= 0 && ny < R&& nx >= 0 && nx < C) {
			if (!visited[ny][nx] && road[ny][nx] != 'T') {
				visited[ny][nx] = 1;
				dfs(ny, nx, dist + 1);
				visited[ny][nx] = 0;
			}
		}
	}

}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> R >> C >> K;
	for (int i = 0; i < R; i++) {
		string s;
		cin >> s;
		road.push_back(s);
	}

	visited[R - 1][0] = 1;
	dfs(R - 1, 0, 1);
	cout << ret;
	
	return 0;
}

