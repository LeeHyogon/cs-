#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
#define INF 987654321
#define LINF 321321321321

int N;
int arr[1000001];
int dp[1000001];

//길이가 홀수일땐 mid가 중간 짝수일때는, 1개작
int find(int start, int end, int num) {

	while (start < end) {
		int mid = (start + end) / 2;

		if (dp[mid] < num) {
			start = mid + 1;
		}
		else  {
			end = mid;
		}
	}
	return start;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	dp[0] = arr[0];
	int j = 0;
	for (int i = 1; i < N; i++) {
		if (dp[j] < arr[i]) {
			j++;
			dp[j] = arr[i];
		}
		else if (dp[j] > arr[i]) {
			int index = find(0, j,arr[i]);
			dp[index] = arr[i];
		}
	}

	cout << j + 1;
	return 0;
}

