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
#define INF 987654321

#define MAX 4001
int N, K;
int cache[201][201];
int arr[201];
int bulb(int l, int r) {

	if (l == r) return 0;

	int &ret = cache[l][r];

	if (ret != -1) return ret;
	ret = INF;
	for (int i = l; i < r; i++) {
		ret = min(ret, bulb(l, i) + bulb(i + 1, r) + (arr[l] != arr[i+1] ? 1 : 0 ));
	}

	return ret;
}



int main(void) {
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
		cin >> arr[i];


	memset(cache, -1, sizeof(cache));
	cout << bulb(1, N);

	return 0;
}