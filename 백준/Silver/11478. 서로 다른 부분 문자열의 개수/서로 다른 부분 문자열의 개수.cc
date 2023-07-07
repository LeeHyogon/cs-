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

string s;
set<string> st;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;
	
	for (int i = 0; i < s.size(); i++) {
		string tmp;
		for (int j = i; j < s.size(); j++) {
			tmp += s[j];
			st.insert(tmp);
		}
	}
	cout << st.size();

	return 0;
}

