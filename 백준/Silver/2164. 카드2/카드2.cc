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


queue<int> q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int a;
	cin >> a;

	for (int i = 1; i <= a; i++) {
		q.push(i);
	}


	while (q.size()>1) {
		
		q.pop();
		if (q.size() == 1)
			break;
		int head = q.front();
		q.pop();
		q.push(head);

	}
	cout << q.front();

	return 0;
}

