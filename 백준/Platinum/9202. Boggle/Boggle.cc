#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
int dx[8] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
set<string> ans;
string map[4], wordMax;
bool visit[4][4];
int wordSizeMax = 0;
int maxScore = 0;
class Node {
	public:
		char data;    //문자 저장 변수
		string strData;   // 단어 저장할 변수
		vector<Node*> child;
};
class Trie{
	private:
		Node* root = new Node;
	public:
		void push(string str){
			insert(str, 0, root);
		}
		void insert(string str, int idx, Node* node){
			if(idx >= str.length()){
				node->strData = str;   // 단어 저장
				return;
			}
			int next = -1;
			for(int i=0; i<node->child.size(); i++){
				if(str[idx] == node->child[i]->data){
					next = i;
					break;
				}
			}
			if(next != -1){
				insert(str, idx+1, node->child[next]);
			}
			else{
				Node* newNode = new Node;    //해당 문자 없다면 노드 새로 생성
				newNode->data = str[idx];
				node->child.push_back(newNode);
				insert(str, idx+1, newNode);
			}
		}
		bool search(string str){
			return findWord(str, 0, root);
		}
		bool findWord(string str, int idx, Node* node){
			if(!node->child.empty() && idx >= str.length())	{
				if(node->strData == str)	return true;    //리프노드는 아니지만 해당 단어가 존재하는 곳
				else	return false;	
			}
			if(idx >= str.length())	return true;  // 리프노드
			int next = -1;
			for(int i=0; i<node->child.size(); i++){
				if(str[idx] == node->child[i]->data){
					next = i;
					break;
				}
			}
			if(next != -1)	return findWord(str,idx+1,node->child[next]); // 동일 문자 존재 
			else	return false; //검색 실패
		}
};
Trie* trie = new Trie;
int score(int size){
	switch (size){
		case 1: 
		case 2:
			return 0;
			break;
		case 3:
		case 4: 
			return 1;
			break;
		case 5:
			return 2;
			break;
		case 6:
			return 3;
			break;
		case 7:
			return 5;
			break;
		case 8:
			return 11;
			break;
	}
	return 0;
}
void dfs(int x, int y, string word){
	if(visit[x][y])	return;  //이미 방문
	if(word.size() > 8){  //8자리 단어가 최대
		return;
	}
	if(trie->search(word)){   // 단어 존재 여부 검사
		if(ans.find(word) == ans.end()){  // 단어 중복 여부 검사
			ans.insert(word);  // set에 삽입
			maxScore += score(word.length());   //점수 합계
			if(word.length() > wordSizeMax){   // 더 긴 단어 찾기
				wordSizeMax = word.length();
				wordMax = word;   
			}
			else if(word.length() == wordSizeMax){
				wordMax = min(wordMax, word);   //사전 순 
			}
		}
	}
	visit[x][y] = true;
	for(int i=0; i<8; i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(nx < 0 || ny < 0 || nx >= 4|| ny >= 4)	continue;
		word += map[nx][ny];  
		dfs(nx, ny, word);
		word.pop_back();
	}
	visit[x][y] = false; 
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int w, b;
	cin >> w;
	for(int i=0; i<w; i++){
		string s;
		cin >> s;
		trie->push(s);
	}

	cin >> b;
	for(int i=0; i<b; i++){
		for(int j=0; j<4; j++){
			cin >> map[j];
		}
		for(int m=0; m<4; m++){
			for(int n=0; n<4; n++){
				visit[m][n]  = false;
			}
		}
		ans.clear();
		wordSizeMax = 0; 	maxScore = 0;	wordMax.clear();
		for(int k=0; k<4; k++){ 
			for(int l=0; l<4; l++){
				string s;
				s.push_back(map[k][l]);
				dfs(k, l, s);
			}
		}
		cout << maxScore << " " << wordMax << " " << ans.size()<< "\n";
	}

	return 0;
}