class Solution {
public:
    int solve(int ind, int prev, vector<int>& nums, vector<vector<int>> &dp) {
        // base case
        if(ind == nums.size()) return 0;

        if(dp[ind][prev+1] != -1) return dp[ind][prev+1];

        int take = 0;  
        if(prev == -1 || nums[ind] > nums[prev]) {
            take = 1 + solve(ind+1, ind, nums, dp);    
        }
        int nottake = 0 + solve(ind+1, prev, nums, dp);

        return dp[ind][prev+1] = max(take, nottake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // dp[index][prevIndex] 
        // index : 0 -> n-1
        // prevIndex : 0 -> n
        vector<vector<int>> dp(n, vector<int> (n+1, -1));
        return solve(0, -1, nums, dp);
    }
};