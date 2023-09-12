#include <iostream>
#include <vector>
#include <queue>
#include<string>
#include <algorithm>
#include <cstring> //memset
#include<tuple>
#include<functional>
using namespace std;
typedef long long ll;
typedef pair<int, int > pii;
const ll MAX = 1000000;
const int INF = 87654321;
const int NUM = 1000000 + 5;
ll seg[ (NUM+1) * 4] = {};
ll arr[NUM] = {};
int N, M;
struct Segtree {
	
	ll update(int index, ll value,int node,int nodeL, int nodeR) {
		if (index<nodeL || index>nodeR) return seg[node];
		if (nodeL == nodeR) {
			//cout << index << " " << value <<" "<<nodeL <<" "<<nodeR<<"\n";
			return seg[node] += value;
		}
		int mid = (nodeL + nodeR) / 2;
		return seg[node] = update(index, value, node * 2, nodeL, mid) + update(index, value, node * 2 + 1, mid + 1, nodeR);
	}

	ll query(int cnt,int node,int nodeL,int nodeR) {
		if (nodeL == nodeR) return nodeL;
		if (seg[node*2] >= cnt)
			return query(cnt, node * 2, nodeL, (nodeL + nodeR) / 2);
		else
			return query(cnt - seg[node*2], node * 2 + 1, (nodeL + nodeR) / 2 + 1, nodeR);
	}
};
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int A, B, C;
		cin >> A >> B;
		Segtree tree;
		if (A == 2) {
			cin >> C;
			//B맛 사탕 넣기
			if (C > 0) {
				tree.update(B, C, 1, 1, NUM);
			}
			//B맛 사탕 빼기
			else if (C < 0) {
				tree.update(B, C, 1, 1, NUM);
			}
		}
		//B등인 사탕 꺼내서 출력하기 
		else if (A == 1) {
			int index = tree.query(B, 1, 1, NUM);
			cout << index << "\n";
			tree.update(index, -1, 1, 1, NUM);
		}

	}





	return 0;
}