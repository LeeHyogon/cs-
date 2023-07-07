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


map<string, int> StoV;
map<int, string> VtoS;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <=n; i++) {
		string s;
		cin >> s;
		StoV[s] = i;
		VtoS[i] = s;
	}
	vector<string> s2;
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		s2.push_back(s);

	}

	for (int i = 0; i < m; i++) {
		int tmp = 0;
		if (s2[i][0] >= '1'&& s2[i][0] <= '9') {
			tmp = stoi(s2[i]);
			cout << VtoS[tmp] << "\n";
		}
		else {
			cout << StoV[s2[i]] << "\n";
		}
	}



	
	return 0;
}

