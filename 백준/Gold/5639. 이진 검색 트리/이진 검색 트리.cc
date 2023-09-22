#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<string>
#include<tuple>
#include<cmath>
#include<functional>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define INF 987654321
#define LINF 321321321321
#define MAX 300

int arr[10010];
int pos;

void postorder(int start, int end) {

	if (start > end) return;

	int last = end;
	if (start == end) {
		cout << arr[start] << endl;
		return;
	}

	
	while (arr[start] < arr[last])
		last--;

	postorder(start+1, last);
	postorder(last + 1, end);
	cout << arr[start] << endl;

}



int main(void)
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);
	

	for (pos = 0; scanf("%d", arr + pos) > 0; pos++);
	
	postorder(0, pos - 1);

	return 0;
}







