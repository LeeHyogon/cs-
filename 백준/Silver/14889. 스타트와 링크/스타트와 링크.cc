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
int N;

int ret = INF;
int arr[MAX][MAX];
bool visited[MAX];
int cnt;

vector<int> start;


int calc() {
	vector<int> link;
	for (int i = 0; i < N; i++) {
		if (!visited[i])
			link.push_back(i);
	}
	/*
	cout << " start : ";
	for (int i = 0; i < start.size(); i++)
		cout << start[i] << " ";
	cout << "\n";

	
	cout << " link : ";
	for (int i = 0; i < link.size(); i++)
		cout << link[i] << " ";
	cout << "\n";
	*/
	int retS = 0;
	int retL = 0;
	for (int i = 0; i <start.size(); i++) {
		for (int j = 0; j < start.size(); j++) {
			if (i == j)continue;
			retS += arr[start[i]][start[j]];
		}
	}

	for (int i = 0; i < link.size(); i++) {
		for (int j = 0; j < link.size(); j++) {
			if (i == j) continue;
			retL += arr[link[i]][link[j]];
		}
	}
	return abs(retS - retL);
}

void DFS(int here) {

	if (here > N) return;
	if (start.size() == (N/2)) {
		ret = min(ret, calc());
		return;
	}
	start.push_back(here);
	visited[here] = 1;
	DFS(here + 1);
	start.pop_back();
	visited[here] = 0;
	DFS(here + 1);


}

int main(void) {

	cin >> N;
	for (int i = 0; i <N; i++)
		for (int j = 0; j <N; j++)
			cin >> arr[i][j];

	DFS(0);
	cout << ret;
	return 0;

}

