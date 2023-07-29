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


int T;
string W;
int K;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;

	for (int Case = 0; Case < T; Case++) {
		vector<int> v[26];
		cin >> W;
		cin >> K;

		for (int i = 0; i < W.size(); i++) {
			v[W[i] - 'a'].push_back(i);
		}
		int retMin = INF;
		int retMax = -1;
		for (int i = 0; i < 26; i++) {
			if (v[i].size() >= K) {
				sort(v[i].begin(), v[i].end());
				int start = 0;
				for (int pos = K - 1; pos < v[i].size(); pos++, start++) {
					retMin = min(retMin, v[i][pos] - v[i][start]);
					retMax = max(retMax, v[i][pos] - v[i][start]);
				}
			}
		}
		if (retMin != INF) {
			cout << retMin + 1 << " " << retMax + 1 << "\n";
		}
		else
			cout << -1 << "\n";
	}

	return 0;
}

