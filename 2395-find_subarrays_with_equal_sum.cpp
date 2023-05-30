// Given a 0-indexed integer array nums, determine whether there exist two subarrays of length 2 with equal sum. 
// Note that the two subarrays must begin at different indices.
// Return true if these subarrays exist, and false otherwise.


class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i=1; i<n; i++) {
            int sum = nums[i] + nums[i-1];
            mp[sum]++;
            if(mp[sum] > 1) return true;
        }
        return false;
    }
};