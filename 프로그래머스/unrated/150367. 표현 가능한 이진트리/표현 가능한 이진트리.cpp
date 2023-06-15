#include <iostream>
#include <cstring>
#include <string>
#include <math.h>
#include <algorithm>
#include <queue>
using namespace std;
#define INF 987654321
#define LINF 321321321321
typedef long long ll;
typedef pair<int, int > pii;

ll N;
int bin[100];
int Size;
void change(long long num) {
	memset(bin, 0, sizeof(bin));
	
	vector<int> v;
	// 5 2 1   
	// 1 0 1  
	// 1 0  
	
	while (num) {
		int s = num % 2;
		num = num / 2;
		v.push_back(s);
	}
	int tmp = v.size();
	int depth = 1;
	while (!(tmp == 1 || tmp == 0)) {
		tmp = tmp / 2;
		depth++;
	}
	// 1 0 1 0 -> 0 1 0 1 -> 0 0 0 0 1 0 1
	Size = pow(2, depth) - 1;

	for (int i = Size; i >= 1; i--) {
		if (Size - i < v.size()) {
			bin[i] = v[Size - i];
		}
		else
			bin[i] = 0;
	}
}
bool eval(int start, int end) {
	if (start == end) {
		return true;
	}
	int mid = (start + end) / 2;
	if (bin[mid] == 0) {
		for (int i = start; i <= end; i++)
			if (bin[i] == 1)
				return false;
		return true;
	}	
	return eval(start,mid-1) && eval(mid+1,end);
}

vector<int> solution(vector<long long> numbers) {
	vector<int> answer;
	for (int i = 0; i < numbers.size(); i++) {
		change(numbers[i]);
		if (eval(1, Size)) {
			answer.push_back(1);
		}
		else
			answer.push_back(0);
	}

	return answer;
}