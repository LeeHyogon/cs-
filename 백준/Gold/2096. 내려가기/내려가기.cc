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
int arr[100004][3];
int lc[3];
int minn = 900001;
int maxn = 0;


int main()
{
	cin >> n;

	for (int i = 0; i <n; i++) {
		for (int j = 0; j < 3; j++)
			cin >> arr[i][j];
	}

	lc[0] = arr[0][0]; lc[1] = arr[0][1]; lc[2] = arr[0][2];

	for (int i = 0; i <n-1; i++) {
		int a = lc[0];
		int b = lc[1]; 
		int c = lc[2];
		lc[0] = min(a + arr[i+1][0], b + arr[i+1][0]);
		lc[1] = min({ a + arr[i+1][1],b + arr[i+1][1],c + arr[i+1][1] });
		lc[2] = min(b + arr[i+1][2], c + arr[i+1][2]);
	}

	int mini = min({ lc[0],lc[1],lc[2] });
	
	lc[0] = arr[0][0]; lc[1] = arr[0][1]; lc[2] = arr[0][2];

	for (int i = 0; i < n - 1; i++) {
		int a = lc[0];
		int b = lc[1];
		int c = lc[2];
		lc[0] = max(a + arr[i + 1][0], b + arr[i + 1][0]);
		lc[1] = max({ a + arr[i + 1][1],b + arr[i + 1][1],c + arr[i + 1][1] });
		lc[2] = max(b + arr[i + 1][2], c + arr[i + 1][2]);
	}
	int maxi = max({ lc[0],lc[1],lc[2] });

	cout << maxi << " " << mini;

	return 0;

}