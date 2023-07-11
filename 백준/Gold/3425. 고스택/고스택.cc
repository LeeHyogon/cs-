#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	while (true) {
		//명령어 저장
		vector <pair<string, int>> commandList;
		while (true) {
			string command;
			int num = 0;
			cin >> command;
			if (command == "QUIT") return 0;
			if (command == "END") break;
			if (command == "NUM")
			{
				cin >> num;
			}
			commandList.push_back({ command,num });
		}

		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			long V;
			bool isValid = true;
			cin >> V;

			int commandSize = commandList.size();

			
			stack<long> Stack;
			Stack.push(V); //초기값 push
			for (int j = 0; j < commandSize; j++) {
				auto cur = commandList[j];
				if (cur.first == "NUM") {
					int n = cur.second;
					Stack.push(n);
					if (abs(n) > 1000000000) {
						isValid = false;
						break;
					}
				}
				else if (cur.first == "POP") {
					if (Stack.empty()) {
						isValid = false;
						break;
					}
					Stack.pop();
				}
				else if (cur.first == "INV") {
					if (Stack.empty()) {
						isValid = false;
						break;
					}
					long n = Stack.top();
					Stack.pop();
					Stack.push(n * -1);
				}
				else if (cur.first == "DUP") {
					if (Stack.empty()) {
						isValid = false;
						break;
					}
					long n = Stack.top();
					Stack.push(n);
				}
				else if (cur.first == "SWP") {
					if (Stack.size() < 2) {
						isValid = false;
						break;
					}
					long first = Stack.top(); Stack.pop();
					long second = Stack.top(); Stack.pop();
					Stack.push(first);
					Stack.push(second);
				}
				else if (cur.first == "ADD") {
					if (Stack.size() < 2) {
						isValid = false;
						break;
					}
					long first = Stack.top(); Stack.pop();
					long second = Stack.top(); Stack.pop();
					if (abs(first + second) > 1000000000) {
						isValid = false;
						break;
					}

					Stack.push(first + second);
				}
				else if (cur.first == "SUB") {
					if (Stack.size() < 2) {
						isValid = false;
						break;
					}
					long first = Stack.top(); Stack.pop();
					long second = Stack.top(); Stack.pop();
					if (abs(second - first) > 1000000000) {
						isValid = false;
						break;
					}

					Stack.push(second - first);
				}
				else if (cur.first == "MUL") {
					if (Stack.size() < 2) {
						isValid = false;
						break;
					}
					long first = Stack.top(); Stack.pop();
					long second = Stack.top(); Stack.pop();
					if (abs(first * second) > 1000000000) {
						isValid = false;
						break;
					}

					Stack.push(first * second);
				}
				else if (cur.first == "DIV") {
					if (Stack.size() < 2) {
						isValid = false;
						break;
					}
					long first = Stack.top(); Stack.pop();
					long second = Stack.top(); Stack.pop();

					if (first == 0) {
						isValid = false;
						break;
					}

					long div = abs(second) / abs(first);
					if (first > 0 && second < 0 || first < 0 && second > 0) {
						div = div * -1;
					}
					if (abs(div) > 1000000000) {
						isValid = false;
						break;
					}
					Stack.push(div);
				}
				else if (cur.first == "MOD") {
					if (Stack.size() < 2) {
						isValid = false;
						break;
					}
					long first = Stack.top(); Stack.pop();
					long second = Stack.top(); Stack.pop();

					if (first == 0) {
						isValid = false;
						break;
					}

					long mod = abs(second) % abs(first);
					if (second < 0) {
						mod = mod * -1;
					}
					if (abs(mod) > 1000000000) {
						isValid = false;
						break;
					}
					Stack.push(mod);
				}
			}

			if (!isValid || Stack.size() > 1 || Stack.empty()) {
				cout << "ERROR" << '\n';
			}
			else {
				cout << Stack.top() << '\n';
			}
		}
		cout << '\n';
	}

	return 0;
}