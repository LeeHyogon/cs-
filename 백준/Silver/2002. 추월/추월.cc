#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <functional>
#include <map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
using namespace std;
#define INF 987654321
#define LINF 321321321321
typedef long long ll;

int n;
queue<string> in;
queue<string> out;
set<string> rec;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		in.push(s);
	}
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		out.push(s);
	}
	
	int ret = 0;
	while (!in.empty() && !out.empty()) {
		if (in.front() != out.front()) {
			auto it = rec.find(in.front());
			if (it != rec.end()) {
				in.pop();
			}
			else {
				string s = out.front();
				out.pop();
				rec.insert(s);
				ret++;
			}
		}
		else {
			in.pop();
			out.pop();
		}
	}
	cout << ret;
	
	return 0;
}

