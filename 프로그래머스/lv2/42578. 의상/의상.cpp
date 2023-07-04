#include <string>
#include <vector>
#include <map>
using namespace std;


map<string, vector<string> > m;
int solution(vector<vector<string>> clothes) {
    int answer = 0;
    for (int i = 0; i < clothes.size(); i++) {
		m[clothes[i][1]].push_back(clothes[i][0]);
	}
	map<string, vector<string> >::iterator iter;
	int tmp = 1;
	for (iter = m.begin(); iter != m.end(); iter++) {
		tmp= tmp*(iter->second.size()+1);
	}
	answer= tmp - 1;
    
    return answer;
}