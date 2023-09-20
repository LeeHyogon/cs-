#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX = 100000 + 1;
int inorder[MAX];
int postorder[MAX];
int idx[MAX];

void Printpreorder(int inbegin,int inend,int postbegin,int postend) {
	if (inbegin > inend || postbegin > postend) return;
	int root = postorder[postend];
		
	cout << root << " ";

	Printpreorder(inbegin,idx[root]-1, postbegin, postbegin+(idx[root]-inbegin)-1);
	Printpreorder(idx[root] + 1, inend, postbegin+(idx[root]-inbegin), postend-1);

}
	

int main(void){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> inorder[i];
	for (int i = 0; i < n; i++)
		cin >> postorder[i];
	
	for (int i = 0; i < n; i++)
		idx[inorder[i]] = i;

	Printpreorder(0, n - 1, 0, n - 1);


	return 0;
}