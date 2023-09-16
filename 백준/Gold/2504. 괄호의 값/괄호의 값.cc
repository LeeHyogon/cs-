#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<string>
#include<tuple>
#include<cmath>
#include<functional>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define INF 987654321
#define LINF 321321321321
#define MAX 300

stack<int> str;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			str.push(-1);
			continue;
		}
		if (s[i] == '[') {
			str.push(-2);
			continue;
		}
		if (s[i] == ')') {
			queue<int> q;
			if (str.empty() || str.top() == -2) {
				cout << 0;
				return 0;
			}
			while (str.top() != -1) {
				q.push(str.top());
				str.pop();
				if (str.empty() ||str.top()==-2) {
					cout << 0;
					return 0;
				}
			}
			str.pop();
			int ret = 0;
			while (!q.empty()) {
				ret += q.front() * 2;
				q.pop();
			}
			if (ret)
				str.push(ret);
			else
				str.push(2);
		}
		else if (s[i] == ']') {
			queue<int> q;
			if (str.empty() || str.top() == -1) {
				cout << 0;
				return 0;
			}

			while (str.top() != -2) {
				q.push(str.top());
				str.pop();
				if (str.empty() ||str.top()==-1 ) {
					cout << 0;
					return 0;
				}
			}
			

			str.pop();
			int ret = 0;
			while (!q.empty()) {
				ret += q.front() * 3;
				q.pop();
			}
			if (ret)
				str.push(ret);
			else
				str.push(3);
		}

	}
	int ans = 0;
	while (!str.empty()) {
		if (str.top() == -2 || str.top() == -1) {
			cout << 0;
			return 0;
		}
		ans += str.top();
		str.pop();
	}
	cout << ans;
	return 0;
}







