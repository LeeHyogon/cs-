#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dp[501][501];
int n;
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    n=triangle.size();
    dp[0][0]=triangle[0][0];
    for(int i=1;i<n;i++){
        for(int j=0; j<=i; j++){
            if(j==0){
                dp[i][j]=dp[i-1][j]+triangle[i][j];
                continue;
            }
            if(i==j){
                dp[i][j]=dp[i-1][j-1]+triangle[i][j];
                continue;
            }
            dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+triangle[i][j];
        }
    }
    
    for(int i=0;i<n;i++){
        answer=max(answer,dp[n-1][i]);    
    }
    
    return answer;
}