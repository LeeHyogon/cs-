#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<algorithm>
#include<stdlib.h>
using namespace std;

#define ll long long


int n;

ll A[4002];
ll B[4002];
ll C[4002];
ll D[4002];

ll AB[16000001];
ll CD[16000001];
int main(void) {

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			if (j == 0)
				cin >> A[i];
			if (j == 1)
				cin >> B[i];
			if (j == 2)
				cin >> C[i];
			if (j == 3)
				cin >> D[i];
		}
	}
	int idx1 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			AB[idx1++] = A[i] + B[j];
		}
	}
	sort(AB, AB + idx1);
	int idx2 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			CD[idx2++] = C[i] + D[j];
		}
	}
	
	sort(CD, CD + idx2);
	int N = idx1;
	int M = idx2;
	int asame, bsame;

	int t = 0;

	int astart = 0;
	int bhigh = M - 1;
	ll ans = 0;
	while (astart < N&&bhigh >= 0) {
		for (asame = astart; asame < N &&AB[astart] == AB[asame]; asame++);
		for (bsame = bhigh; bsame >= 0 && CD[bhigh] == CD[bsame]; bsame--);
		int s = AB[astart] + CD[bhigh];
		if (t > s) {
			astart = asame;
		}
		else {
			if (t == s) ans += (ll)(asame - astart)*(bhigh - bsame);
			bhigh = bsame;
		}
	}


	cout << ans << endl;




}