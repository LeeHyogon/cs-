#include<bits/stdc++.h>
using namespace std;
int T;
long long dp[101];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>T;
    for(int i=0;i<T;i++){
        int n;
        cin>>n;
        dp[1]=dp[2]=dp[3]=1;
        dp[4]=dp[5]=2;
        for(int i=6;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-5];
        }
        cout<<dp[n]<<endl;
    }

    return 0;
}