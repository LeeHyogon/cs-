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

int n;
int arr[1000001];
int x;
set<int> s;
int ret = 0;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> x;

	for (int i = 0; i < n; i++) {
		if (arr[i] >= x)
			continue;
		auto it = s.find(arr[i]);
		if (it == s.end()) {
			s.insert(x - arr[i]);
		}
		else
			ret++;
	}
	cout << ret;
	return 0;
}

