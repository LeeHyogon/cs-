#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
#define INF 987654321
#define LINF 321321321321
typedef long long ll;
typedef pair<int, int > pii;

int N, M, H;
int target_cnt;
int col[40][40];
bool isPromising() {
	for (int i = 1; i <= N; i++) {
		int cur = i;
		for (int j = 1; j <= H; j++) {
			if ( col[j][cur]) {
				cur++;
			}
			else if ( col[j][cur - 1]) {
				cur--;
			}
		}
		if (cur != i)
			return false;
	}
	return true;
}
int ret = -1;

void DFS(int cnt, int depth) {
	if (cnt == target_cnt){
		if (isPromising()){
			if (ret == -1){
				ret = cnt;
			}
			else
				ret = min(cnt, ret);
		}
		return;
	}
	for (int j = 1; j < N; j++) {
		for (int i = depth; i <= H; i++) {
			if (!(col[i][j - 1] || col[i][j] || col[i][j + 1])) {
				col[i][j] = 1;
				DFS(cnt + 1, depth);
				col[i][j] = 0;
				while (!col[i][j - 1] && !col[i][j + 1]) i++;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> H;

	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		col[a][b] = 1;
	}
	for (int i = 0; i <= 3; i++) {
		target_cnt = i;
		DFS(0, 1);
		if (ret != -1) {
			cout << ret;
			return 0;
		}
	}
	cout << ret;
	return 0;
}

