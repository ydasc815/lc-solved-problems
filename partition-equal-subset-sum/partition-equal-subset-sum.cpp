class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0; i<nums.size(); i++) sum += nums[i];
        if(sum%2 != 0) return false;
        else return subsetSum(nums, sum/2);
    }
    
    bool subsetSum(vector<int>& arr, int sum) {
        int n = arr.size(), w = sum;
        vector<vector<bool>> dp(n+1, vector<bool> (w+1, false));
        for(int i=0; i<n+1; i++) {
            for(int j=0; j<w+1; j++) {
                if(i == 0) dp[i][j] = false;
                if(j == 0) dp[i][j] = true;
                if(i > 0 && j > 0) {
                    dp[i][j] = dp[i-1][j];
                    if(arr[i-1] <= j) {
                        dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i][j];
                    } 
                }
            }
        }
        return dp[n][w];
    }
};