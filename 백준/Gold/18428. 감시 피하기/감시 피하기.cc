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


char board[10][10];
char repli[10][10];
int visited[7][7];
int N;
int student = 0;
vector<pii> t;
int Count() {
	int r = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (repli[i][j] == 'S')
				r++;
		}
	}
	return r;
}

bool view(int y, int x) {

	int tx = x;
	while (tx>=0) {
		if (repli[y][tx] == 'O')
			break;
		if (repli[y][tx] == 'S') {
			return false;
		}
		repli[y][tx] = 'T';
		tx--;
	}
	tx = x;
	while (tx<N) {
		if (repli[y][tx] == 'O')
			break;
		if (repli[y][tx] == 'S') {
			return false;
		}
		repli[y][tx] = 'T';
		tx++;
	}

	int ty = y;
	while (ty >= 0) {
		if (repli[ty][x] == 'O')
			break;
		if (repli[ty][x] == 'S') {
			return false;
		}
		repli[ty][x] = 'T';
		ty--;
	}
	ty = y;
	while (ty < N) {
		if (repli[ty][x] == 'O')
			break;
		if (repli[ty][x] == 'S') {
			return false;
		}
		repli[ty][x] = 'T';
		ty++;
	}
	return true;
}
void copy() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			repli[i][j] = board[i][j];
		}
	}
}


void DFS(int y, int x, int cnt) {

	if (cnt == 3) {
		copy();
		bool chk = true;
		for (int i = 0; i < t.size(); i++) {
			if (!view(t[i].first, t[i].second))
				chk = false;
		}
		if (chk) {
			cout << "YES\n";
			exit(0);
		}
		else
			return;
	}
	int tx = x;
	for (int i = y; i < N; i++) {
		for (int j = tx; j < N; j++) {
			if (board[i][j] == 'X' && !visited[i][j]) {
				visited[i][j] = 1;
				board[i][j] = 'O';
				DFS(i, j, cnt + 1);
				board[i][j] = 'X';
				visited[i][j] = 0;
			}
		}
		tx = 0;
	}

}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			repli[i][j] = board[i][j];
			if (board[i][j] == 'T')
				t.push_back({ i,j });
			if (board[i][j] == 'S')
				student++;
		}
	}
	DFS(0, 0, 0);

	cout << "NO";

	return 0;
}

