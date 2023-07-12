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

int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

int R, C, N;


vector<string> board;
int Time[201][201];


void bomb(int y, int x) {
	board[y][x] = '.';
	Time[y][x] = 0;
	for (int dir = 0; dir < 4; dir++) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		
		if (ny >= 0 && ny < R && nx >= 0 && nx < C) {
			board[ny][nx] = '.';
			Time[y][x] = 0;
		}
	}
}
void Minus() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			Time[i][j]--;
		}
	}
}
void AddBomb() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (board[i][j]=='.') {
				board[i][j] = 'O';
				Time[i][j] = 3;
			}
		}
	}
}
void chk() {
	vector<pii> v;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (Time[i][j] == 0 && board[i][j] == 'O') {
				v.push_back({ i,j });
			}
		}
	}
	for (int i = 0; i < v.size(); i++) {
		bomb(v[i].first, v[i].second);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C >> N;

	for (int i = 0; i < R; i++) {
		string s;
		cin >> s;
		board.push_back(s);
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (board[i][j] == 'O')
				Time[i][j] = 3;
		}
	}
	for (int k = 1; k <= N; k++) {
		Minus();
		chk();
		if (k % 2 == 0)
			AddBomb();
		
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << board[i][j];
		}
		cout << "\n";
	}
	return 0;
}

