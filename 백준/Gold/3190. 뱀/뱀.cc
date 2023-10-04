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
#define MAX 300

struct head {
	int y, x;
	int dir;
};

int N, K, L;
int visited[10010];
int board[MAX][MAX];
int ret = 0;
vector<head> snake;
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
vector<pii> order;

void Print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << board[i][j] << " ";

		cout << "\n";
	}
}

bool move() {
	
	//cout << "dir: " << snake[0].dir << " \n";
	//Print();
	//cout << "\n";
	//1초 증가
	ret++;
	bool chk = true;
	bool eat = false;
	int tail = snake.size() - 1;
	int dir = snake[0].dir;	
	int ny = snake[0].y + dy[dir];
	int nx = snake[0].x + dx[dir];
	if (ny < 0 || ny >= N || nx < 0 || nx >= N) return false;
	//몸통부딪힘.
	if (board[ny][nx] == 1)
		return false;
	
	//먹은경우 뒤에 추가.
	if (board[ny][nx] == 2) {
		board[ny][nx] = 1;
		eat = true;
		snake.push_back({ snake[tail].y,snake[tail].x });
	}
	//안먹었으면 꼬리 흔적지우기
	if (!eat) {
		board[snake[tail].y][snake[tail].x] = 0;
	}
	board[ny][nx] = 1;
	for (int i = tail;  i>0; i--) {
		snake[i].y = snake[i - 1].y;
		snake[i].x = snake[i - 1].x;
		board[snake[i - 1].y][snake[i - 1].x] = 1;
	}
	snake[0].y = ny;
	snake[0].x = nx;
	return true;
}

void direct(int lr) {
	int dir = snake[0].dir;
	switch (lr)
	{
		//2 오른쪽방향 틀기
	case 2: {
		if (dir == 0) snake[0].dir = 2;
		else if (dir == 1) snake[0].dir = 3;
		else if (dir == 2) snake[0].dir = 1;
		else if (dir == 3) snake[0].dir = 0;
		break;
	}
			//1 왼쪽 방향 틀기
	case 1: {
		if (dir == 0) snake[0].dir = 3;
		else if (dir == 1) snake[0].dir = 2;
		else if (dir == 2) snake[0].dir = 0;
		else if (dir == 3) snake[0].dir = 1;
		break;
	}
	default:
		break;
	}
}

int main(void)
{
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int y, x;
		cin >> y >> x;
		//2는 사과 1은 뱀
		board[y-1][x-1] = 2;
	}
	cin >> L;
	snake.push_back({ 0,0,0});
	board[0][0] = 1;
	for (int i = 0; i < L; i++) {
		int a;
		string c;
		int b;
		cin >> a >> c;
		c == "L" ? b = 1 : b = 2;
		visited[a] = b;

	}

	for (int i = 0; i < 10010; i++) {
		bool chk=move();
		if (!chk) {
			cout << ret;
			return 0;
		}
		if (visited[i+1]) {
			direct(visited[i+1]);
		}
	}


	return 0;
}







