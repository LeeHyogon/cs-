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

int ret = -INF;
int arr[100001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;

	cin >> N >> K;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int tmp = 0;
	for (int i = 0; i < K; i++) {
		tmp += arr[i];
	}
	ret = max(tmp, ret);

	for (int i = K; i < N; i++) {
		tmp -= arr[i - K];
		tmp += arr[i];
		ret = max(tmp, ret);
	}

	cout << ret;

	return 0;
}

