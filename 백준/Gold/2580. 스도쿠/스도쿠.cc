#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<string>
#include<tuple>
#include<cmath>
#include<functional>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define INF 987654321
#define LINF 321321321321
#define MAX 100

int board[10][10];
vector<pii> loc;

bool promising(int n, int y, int x) {
	//세로열 체크
	for (int i = 1; i <= 9; i++) {
		if (i == y) continue;
		if (board[i][x] == n) {
			return false;
		}
	}
	//가로열 체크
	for (int j = 1; j <= 9; j++) {
		if (x == j) continue;
		if (board[y][j] == n) {
			return false;
		}
	}
	int a = (y - 1) / 3;
	int b = (x - 1) / 3;

	//33판 체크
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			if ((a * 3 + i) == y && (b * 3 + j) == x) continue;
			if (board[(a * 3) + i][(b * 3) + j] == n)
				return false;
		}
	}
	return true;
}
bool chk() {
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++)
			if (!board[i][j])
				return false;
	return true;
}
void Print() {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
}

void DFS(int n, int index) {

	if (index > loc.size()) return;
	//cout << "\n";
	//Print();		
	if (chk() && n != 10) {
		Print();
		exit(0);
	}
	else {
		for (int num = 1; num <= 9; num++) {
			if (promising(num, loc[index].first, loc[index].second)) {
				board[loc[index].first][loc[index].second] = num;
				DFS(num, index + 1);
			}
			board[loc[index].first][loc[index].second] = 0;
		}
	}


}


int main(void) {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> board[i][j];
			if (!board[i][j])
				loc.push_back({ i,j });
		}
	}

	DFS(10, 0);
	return 0;

}