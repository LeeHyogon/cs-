#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <functional>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
using namespace std;
#define INF 987654321
#define LINF 321321321321
typedef long long ll;

ll T;
priority_queue<ll> big;
priority_queue<ll, vector<ll>, greater<ll> > small;
map<ll, ll> cnt;

void cleanPQ() {
	while (!big.empty() && cnt[big.top()] == 0) {
		big.pop();
	}
	while (!small.empty() && cnt[small.top()] == 0) {
		small.pop();
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for (int Case = 0; Case < T; Case++) {
		while (!big.empty())
			big.pop();
		while (!small.empty())
			small.pop();
		cnt.clear();
		ll N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			char c; ll n;
			cin >> c >> n;
			if (c == 'I') {
				small.push(n);
				big.push(n);
				cnt[n]++;
			}
			else {
				if (n == 1) {
					if (!big.empty()) {
						cnt[big.top()]--;
						big.pop();
					}
				}
				else if(n==-1) {
					if (!small.empty()) {
						cnt[small.top()]--;
						small.pop();
					}
				}
				cleanPQ();
			}
		}
		cleanPQ();
		if (big.empty() || small.empty()) {
			cout << "EMPTY\n";
		}
		else {
			cout << big.top() << " " << small.top() << "\n";
		}
		
	}

	
	return 0;
}

