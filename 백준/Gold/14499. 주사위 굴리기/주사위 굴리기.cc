#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<string>
#include<cmath>
#include<functional>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define INF 987654321
#define LINF 321321321321
#define MAX 1100

int gps[MAX][MAX];
int N, M, K;

int ndice[7];
int dice[7];
//0: 제자리 1:동 2:서 3:북 4:남
int dx[5] = { 0, 1,-1,0,0 };
int dy[5] = { 0, 0, 0,-1,1 };

//현재 좌표위치
int hx, hy;

int ex=1,ey=1;



int main(void) {
	cin >> N >> M >> hy >> hx >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> gps[i][j];

	for (int i = 0; i < K; i++) {
		int tmp;
		cin >> tmp;
		int nx = hx + dx[tmp];
		int ny = hy + dy[tmp];		
		if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;

		if (tmp == 1){
			ndice[1] = dice[4];
			ndice[4] = dice[6];
			ndice[6] = dice[3];
			ndice[3] = dice[1];
		}
		else if (tmp==2) {
			ndice[1] = dice[3];
			ndice[4] = dice[1];
			ndice[6] = dice[4];
			ndice[3] = dice[6];
		}
		else if (tmp == 3) {
			ndice[1] = dice[5];
			ndice[2] = dice[1];
			ndice[6] = dice[2];
			ndice[5] = dice[6];
		}
		else if (tmp == 4) {
			ndice[1] = dice[2];
			ndice[2] = dice[6];
			ndice[6] = dice[5];
			ndice[5] = dice[1];
		}
		if (gps[ny][nx] == 0) {
			gps[ny][nx] = ndice[6];
		}
		else {
			ndice[6] = gps[ny][nx];
			gps[ny][nx] = 0;
		}
		cout << ndice[1] << "\n";
		
		for (int j = 0; j < 7; j++) {
			dice[j] = ndice[j];
		}
		hy = ny;
		hx = nx;
	}


	return 0;
}

