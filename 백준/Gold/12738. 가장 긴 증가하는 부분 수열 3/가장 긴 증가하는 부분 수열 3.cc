#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
#define INF 987654321
#define LINF 321321321321
typedef long long ll;

ll N;
ll arr[2000001];
ll dp[2000001];

ll outBound(ll start, ll end, ll target) {

	while (start+1 < end) {
		ll mid = (start + end) / 2;

		if (dp[mid] < target) {
			start = mid;
		}
		else if (dp[mid] > target) {
			end = mid;
		}
		else
			return mid;
	}
	return end;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	for (ll i = 0; i < N; i++) {
		cin >> arr[i];
	}
	dp[0] = arr[0];
	ll j = 0;
	for (ll i = 1; i < N; i++) {
		if (dp[j] < arr[i]) {
			j++;
			dp[j] = arr[i];
		}
		else {
			if (dp[0] > arr[i]) {
				dp[0] = arr[i];
				continue;
			}
			ll index = outBound(-1, j+1,arr[i]);
			dp[index] = arr[i];
		}
	}
	
	
	cout << j + 1;
	return 0;
}

