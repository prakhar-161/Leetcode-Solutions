class Solution {
public:
    int solve(int ind, int target, vector<int>& nums, vector<vector<int>> &dp) {
        if(target == 0) return 1;
        if(ind == nums.size()) return 0;
        
        if(dp[ind][target] != -1) return dp[ind][target];
        
        int notpick = solve(ind+1, target, nums, dp);
        int pick = 0;
        if(nums[ind] <= target) {
            pick = solve(0, target-nums[ind], nums, dp);
        }
        
        return dp[ind][target] = pick + notpick;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (target+1, -1));
        return solve(0, target, nums, dp);
    }
};

// why 1d-dp