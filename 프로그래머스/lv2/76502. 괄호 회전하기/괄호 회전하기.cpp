#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

bool isRight(string s) {

	stack<char> st;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '[' || s[i] == '(' || s[i] == '{') {
			st.push(s[i]);
		}
		else {
			if (s[i] == ']') {
				if (st.empty() ||st.top() != '[')
					return false;
				else
					st.pop();
			}
			else if (s[i] == ')') {
				if (st.empty() || st.top() != '(')
					return false;
				else
					st.pop();
			}
			else if (s[i] == '}') {
				if (st.empty() || st.top() != '{')
					return false;
				else
					st.pop();
			}
		}
	}
	if (!st.empty())
		return false;
	return true;
}



string rotate(queue<char> q,int x) {

	for (int i = 0; i < x; i++) {
		char c = q.front();
		q.push(c);
		q.pop();
	}
	string s = "";
	while (!q.empty()) {
		s += q.front();
		q.pop();
	}
	return s;
}

int solution(string s) {
	int answer = 0;
	queue<char> q;
	for (int i = 0; i < s.size(); i++) {
		q.push(s[i]);
	}

	for (int x = 0; x < s.size(); x++) {
		string tmp = rotate(q, x);
		if (isRight(tmp))
			answer++;
	}


	return answer;
}