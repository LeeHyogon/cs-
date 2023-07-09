#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <functional>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <stack>
#include <queue>
using namespace std;
#define INF 987654321
#define LINF 321321321321
typedef long long ll;
typedef pair<int, int > pii;

unordered_map <string, vector<int>> um;

void addCases(string *s, int score)
{
	for (int i = 0; i < 16; i++)
	{
		string str = "";
		int num = i;
		for (int j = 3; j >= 0; j--)
		{
			if (num <= 0 || num % 2 == 0)
			{
				str = "-" + str;
			}
			else str = s[j] + str;
			num /= 2;
		}
		//cout << "str: " << str << " \n";
		um[str].push_back(score);
	}
}
vector<int> solution(vector<string> info, vector<string> query) {
	vector<int> answer;
	string s[4], str = "";

	for (int i = 0; i < info.size(); i++)
	{
		istringstream stt(info[i]);
		stt >> s[0] >> s[1] >> s[2] >> s[3] >> str;
		addCases(s, (int)stoi(str));
	}

	for (auto itr = um.begin(); itr != um.end(); itr++)
	{
		sort(itr->second.begin(), itr->second.end());
	}

	for (int i = 0; i < query.size(); i++)
	{
		istringstream stt(query[i]);
		stt >> s[0] >> str >> s[1] >> str >> s[2] >> str >> s[3] >> str;
		int score = (int)stoi(str);

		vector <int> v = um[s[0] + s[1] + s[2] + s[3]];
		if (v.size() != 0)
		{
			int ret = 0;
			for (int i = 0; i < v.size(); i++) {
				if (v[i] >= score) {
					ret++;
				}
			}
			answer.push_back(ret);
		}
		else answer.push_back(0);
	}
	return answer;
}