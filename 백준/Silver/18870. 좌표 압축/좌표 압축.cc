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

int N;
vector<ll> v;
vector<ll> ori;
int Lower_bound(int start, int end, int target) {

	int mid = (start + end) / 2;

	while (start+1 < end) {
		mid = (start + end) / 2;

		if (v[mid] <= target) {
			start = mid;
		}
		else
			end = mid;
	}
	return start;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		ll a;
		cin >> a;
		v.push_back(a);
		ori.push_back(a);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end()); // 중복값 제거

	for (int i = 0; i < ori.size(); i++) {
		cout << Lower_bound(-1, v.size(), ori[i]) << " ";
	}


	

	return 0;
}

