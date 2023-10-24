#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;

int main(void) {
	int num = 0, max = 0;
	int check[5] = { 0 };
	vector<vector<int> >  v(5,vector<int>(4));
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 4; j++)
			cin >> v[i][j];
	for(int n=0;n<5;n++)
		for (int k = 0; k < 4; k++) {
			check[n] += v[n][k];
	}
	for(int a=0;a<5;a++)
		if (max < check[a]) {
			max = check[a];
			num = a + 1;
		}
	cout << num << " " << max;

	return 0;

}