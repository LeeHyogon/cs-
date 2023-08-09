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

ll A, B, C;

ll Pow(ll A, ll B) {

	if (B == 0)
		return 1;
	if (B == 1) {
		return A % C;
	}
	ll k = Pow(A, B / 2) % C;

	if (B % 2 == 1)
		return k * k%C*A%C;
	return k * k%C;

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> A >> B >> C;


	cout << Pow(A, B) % C;


	return 0;
}

