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

ll N, K;
ll W[100001], V[100001];
ll bag[101][100001];
int main() {
		
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		cin >> W[i] >> V[i];

	for (int i = 1; i <= N; i++) {
		ll weight = W[i];
		ll value = V[i];
		for (int j = 1; j <= K; j++) {
			if (j-weight >= 0) {
				bag[i][j] = max(bag[i - 1][j], bag[i-1][j - weight] + value);
			}
			else
				bag[i][j] = bag[i - 1][j];
		}
	}

	cout << bag[N][K];
	
	return 0;
}

