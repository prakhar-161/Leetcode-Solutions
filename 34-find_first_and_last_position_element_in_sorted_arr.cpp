class Solution {
public:
    bool binarySearch(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(nums[mid] == target) return true;
            else if(nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        if(binarySearch(nums, target) == true) {
            int first = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
            int last = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
            return {first, last-1};
        } 
        return {-1, -1};    
    }
};