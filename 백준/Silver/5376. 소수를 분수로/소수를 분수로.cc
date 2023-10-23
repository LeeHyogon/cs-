#include <iostream>
#include <vector>
#include <queue>
#include<string>
#include <algorithm>
#include <cstring> //memset
#include<tuple>
#include<functional>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int > pii;
#define MAX 10000010
char str[(MAX + 7 / 8) + 1];

bool isPrime(int k) {
	return str[k >> 3] & (1 << (k & 7));
}
bool en(int k) {
	return str[k >> 3] &= ~(1 << (k & 7));
}
void eratosthenes() {
	memset(str, 255, sizeof(str));
	en(0);
	en(1);
	int i, j;
	int sqrtn = int(sqrt(MAX));
	for (i = 2; i <= sqrtn; i++) {
		if (isPrime(i)) {
			for (j = i * i; j <= MAX; j += i) {
				en(j);
			}
		}
	}
}
ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a%b);
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	char buf[32];
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> buf;
		int len = strlen(buf);
		int start = 2;
		ll one = 1;
		ll onedc = 0;
		while (start<len &&buf[start] != '(') {
			onedc = onedc * 10 + buf[start] - '0';
			one *= 10;
			start++;
		}
		ll ten = one;
		ll tendc = onedc;
		if (start < len) {
			start++;
			while (start<len &&buf[start] != ')') {
				tendc = tendc * 10 + buf[start] - '0';
				ten *= 10;
				start++;
			}
			ll a = ten - one;
			ll b = tendc - onedc;
			ll g = gcd(a, b);
			cout << b / g << "/" << a / g<<"\n";
		}
		else {
			ll a = one;
			ll b = onedc;
			ll g = gcd(a, b);
			cout << b / g << "/" << a / g<<"\n";
		}
	
	}


	return 0;
}