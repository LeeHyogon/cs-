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

int N, d, k, c;
int food[30001];
int ret = 0;
int m[30001];
int counter = 0;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> d >> k >> c;

	for (int i = 0; i < N; i++)
		cin >> food[i];


	for (int i = 0; i < N + k; i++) {
		if (i >= k) {
			int removeFood = food[(i - k) % N];
			m[removeFood]--;
			if (m[removeFood] == 0)
				counter--;
		}
		int newFood = food[i%N];

		if (m[newFood] == 0) {
			counter++;
		}
		m[newFood]++;

		if (m[c] == 0) {
			ret = max(ret, counter + 1);
		}
		else {
			ret = max(ret, counter);
		}
	}
	cout << ret;


	return 0;
}

