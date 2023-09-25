#include <iostream>
#include <vector>
#include <queue>
#include<string>
#include <algorithm>
#include <cstring> //memset
#include<tuple>
#include<functional>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int > pii;
#define MAX 1000000000

ll bi[210][210];
int n, m, k;
void binomial() {
	bi[1][0] = bi[1][1] = 1;
	for (int n = 1; n <= 200; n++) {
		for (int k = 0; k <= n; k++) {
			if (k == 0 || k == n) {
				bi[n][k] = 1;
				continue;
			}
			bi[n][k] = min((ll)1e9 + 7,bi[n - 1][k] + bi[n - 1][k - 1]) ;
		}
	}
}
void pt(int n, int m, int cnt, int len) {

	if (len <= 0) return;

	if (n == 0) {
		cout << 'z';
		pt(n, m - 1, cnt - bi[n + m - 1][m], len - 1);
	}
	else if (m == 0) {
		cout << 'a';
		pt(n - 1, m, cnt, len - 1);
	}
	else if (cnt <= bi[n + m - 1][m]) {
		cout << 'a';
		pt(n - 1, m, cnt, len - 1);
	}
	else {
		cout << 'z';
		pt(n, m - 1, cnt - bi[n + m - 1][m], len - 1);
	}

}

int main(void)
{
	binomial();

	cin >> n >> m >> k;


	ll lim = bi[n+m][m];
	if (k > lim) {
		cout << -1; return 0;
	}
	pt(n, m, k, n + m);



	return 0;
}