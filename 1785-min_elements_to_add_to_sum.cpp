class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long int sum = 0;
        for(auto it:nums) sum += it;
        long int diff = abs(sum-goal);
        if(diff == 0) return 0;
        
        long int cnt=(diff/limit);
        
        cnt+= (diff%limit!=0) ? 1 : 0;
        return cnt;
    }
};