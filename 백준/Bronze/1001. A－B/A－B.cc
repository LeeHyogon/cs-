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
#define M 5
#define MAX_CHILDREN M
#define MAX_KEYS MAX_CHILDREN-1
#define MIN_KEYS (int)(ceilM(2.0))-1 //최소 키 갯수 구하는 식
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b;

	cin >> a >> b;
	cout << a - b;

	return 0;
}



