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

ll N, M;
ll arr[1000001];
ll Cut(ll target) {
	ll ret = 0;

	for (int i = 0; i < N; i++) {
		ll tmp = arr[i] - target;
		if (tmp > 0) {
			ret += tmp;
		}
	}
	return ret;
}
ll Tree() {
	ll start = 0;
	ll end = 2000000001;
	while (start + 1 < end) {
		ll mid = (start + end) / 2;

		ll C = Cut(mid);
		if (C >= M) {
			start = mid;
		}
		else {
			end = mid;
		}
	}
	return start;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	cout << Tree();

	return 0;
}

