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
int N, K;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	string input;
	cin >> input;
	stringstream ss(input);
	string tmp;
	vector<int> v;
	while (getline(ss, tmp, ',')) {
		v.push_back(stoi(tmp));
	}
	int Size = v.size();
	for (int j = 0; j < K; j++) {
		for (int i = 0; i < Size-1; i++) {
			v[i] = v[i + 1] - v[i];
		}
		Size--;
	}
	for (int i = 0; i < Size-1; i++) {
		cout << v[i] << ",";
	}
	cout << v[Size-1];


	
	
	return 0;
}

