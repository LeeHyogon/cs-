#include <iostream>
#include <vector>
#include <queue>
#include<string>
#include <algorithm>
#include<cmath>
#include <cstring> //memset
#include<tuple>
using namespace std;
#define ll long long 

ll arr[10001];
ll K, N,Max;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		cin >> arr[i];
		if (arr[i] > Max)
			Max = arr[i];
	}
	ll high = Max;
	ll low = 1;
	ll mid = high / 2;
	ll ret;
	ll ans = 0;

	while (low <=high) {

		ret = 0;
		mid = (low+high) / 2;
		for (int i = 0; i < K; i++) {
			ret += (arr[i] /mid);
		}
		if (ret < N) {
			high = mid - 1;
		}
		else {
			low = mid + 1;	
			if (ans < mid) ans = mid;
		}
	}

	cout << ans;
		
	return 0;
}

