#include <iostream>
#include <cstdio>
#include <stack>
#include<algorithm>
using namespace std;

typedef pair<int, int> pii;

int arr[1000001];
int lis[1000001];
pii ans[1000001]; // first :: lis가 될 수 있는 위치, second :: 해당하는 값
stack<int> s;


int _lower_bound(int start, int end, int target)
{
	int mid;

	while (start < end)
	{
		mid = (start + end) / 2;

		if (lis[mid] < target)
			start = mid + 1;

		else
			end = mid;
	}

	return end + 1;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int plis = 0;
	int pArr = 1;
	lis[plis] = arr[0];
	ans[0].first = 0;
	ans[0].second = arr[0];

	while (pArr < n) {
		if (lis[plis] < arr[pArr]) {
			lis[++plis] = arr[pArr];
			ans[pArr].first = plis;
			ans[pArr].second = arr[pArr];
		}
		else {
			int pos = _lower_bound(0, plis, arr[pArr]);
			lis[pos - 1] = arr[pArr];

			ans[pArr].first = pos - 1;
			ans[pArr].second = arr[pArr];
		}
		pArr++;
	}
	cout << plis + 1 << endl;
	int t = plis;

	for (int i = n - 1; i >= 0; i--)
	{
		if (ans[i].first == t)
		{
			s.push(ans[i].second);
			t--;
		}
	}

	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	return 0;
}