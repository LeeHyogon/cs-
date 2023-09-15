#include <iostream>
#include <vector>
#include <queue>
#include<string>
#include <algorithm>
#include <cstring> //memset
#include<tuple>
using namespace std;
typedef long long ll;
typedef pair<int, int > pii;
const ll MAX = 1000000000;
const int INF = 87654321;
const int NUM = 500000 + 1;
int seg[NUM * 4] = {};
int arr[NUM] = {};
int zip[NUM] = {};
int N, M;
struct Segtree {

	int query(int l, int r, int node, int nodeL, int nodeR) {
		if (nodeL > r || nodeR < l) return 0;
		if (l <= nodeL && nodeR <= r) return seg[node];
		int mid = (nodeL + nodeR) / 2;
		return (query(l, r, node * 2, nodeL, mid)+ query(l, r, node * 2 + 1, mid + 1, nodeR));
	}
	int update(int index, int value, int node, int nodeL, int nodeR) {
		if (index < nodeL || nodeR < index) return seg[node];
		if (nodeL == nodeR) return seg[node] = value;
		int mid = (nodeL + nodeR) / 2;
		return seg[node] = update(index, value, node * 2, nodeL, mid) + update(index, value, node * 2 + 1, mid + 1, nodeR);

	}

	int init(int l, int r, int node) {
		if (l == r) return seg[node] = arr[l];
		int mid = (l + r) / 2;
		return seg[node] = init(l, mid, node * 2)+init(mid + 1, r, node * 2 + 1);
	}

};


int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <=N; i++) {
		cin >> arr[i];
	}
	vector<pii> V;
	for (int i = 1; i <=N; i++) {
		V.push_back({ arr[i],i });
	}
	sort(V.begin(), V.end());
	reverse(V.begin(), V.end());
	Segtree Tree;
	for (auto &p : V) {
		zip[p.second] = Tree.query(1, p.second, 1, 1, N);
		Tree.update(p.second, 1, 1, 1, N);
	}
	for (int i = 1; i <= N; i++) {
		cout << zip[i] + 1 << "\n";
	}
	

	return 0;
}