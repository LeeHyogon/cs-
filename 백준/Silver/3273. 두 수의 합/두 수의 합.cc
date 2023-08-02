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


int arr[2000002];
int n;

int x;
int ret = 0;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		arr[t]++;
	}
	cin >> x;
	int ret = 0;

	if (x % 2 == 0) {
		for (int i = 1; i <= x / 2 - 1; i++) {
			ret += (arr[i] * arr[x - i]);
		}
		ret += ((arr[x / 2] * (arr[x / 2] - 1)) / 2);
	}
	else {
		for (int i = 1; i <= x / 2; i++) {
			ret += (arr[i] * arr[x - i]);
		}
	}
	cout << ret;

	
	return 0;
}

