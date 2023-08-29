#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <functional>
#include <map>
#include <set>
#include <sstream>
#include <stack>
#include <queue>
using namespace std;
#define INF 987654321
#define LINF 321321321321
#define MOD 9901
typedef long long ll;

int N;
int M;
map<int,int> m;
vector<int> arr;
vector<int> ans;
bool isFind(int target) {
	int start = -1; int end = arr.size();
	while (start + 1 < end) {
		int mid = (start + end) / 2;
		if (arr[mid] <= target) {
			start = mid;
		}
		else{
			end= mid;
		}
	}
	return arr[start] == target ? true : false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i <N; i++) {
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
		auto it = m.find(tmp);
		if (it != m.end()) {
			m[tmp] += 1;
		}
		else
			m[tmp] = 1;
	}
	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());

	cin >> M;
	for (int i = 0; i < M; i++) {
		int tmp;
		cin >> tmp;

		if (isFind(tmp)) {
			ans.push_back(m[tmp]);
		}
		else
			ans.push_back(0);
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	return 0;
}



