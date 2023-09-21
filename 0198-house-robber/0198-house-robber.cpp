class Solution {
public:
    int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n+1,0);
    for(int i = 1;i<n+1;i++){
        if (i >1)
        dp[i] = max(nums[i-1] + dp[i-2] ,dp[i-1]);
        else 
        dp[i] = max(nums[i-1]  ,dp[i-1]);

    }  
    return dp[n];
    }
};