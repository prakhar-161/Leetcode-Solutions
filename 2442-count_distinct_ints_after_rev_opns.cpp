class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        for(int i=0; i<n; i++) {
            s.insert(nums[i]);
            int temp = nums[i];
            int rev = 0;
            while(temp != 0) {
                rev = rev * 10 + temp % 10;
                temp = temp / 10;
            }
            s.insert(rev);
        }
        return s.size();
    }
};