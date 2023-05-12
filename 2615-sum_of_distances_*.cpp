// You are given a 0-indexed integer array nums. 
// There exists an array arr of length nums.length, where arr[i] is the sum of |i - j| over all j such that nums[j] == nums[i] and j != i. 
// If there is no such j, set arr[i] to be 0.
// Return the array arr.


// gives TLE
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, long long int> mpp;
        for(int i=0; i<n; i++) {
            mpp[i] = nums[i];
        }
        
        vector<long long> ans(n, 0);  
        for(int i=0; i<n; i++) {
            for(auto it : mpp) {
                if(it.second == nums[i]) {
                    ans[i] += abs(it.first - i);
                }
            }
        }
        return ans;
    }
};
