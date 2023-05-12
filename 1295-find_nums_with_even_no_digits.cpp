int countDigit(int n) {
        return floor(log10(n) + 1);
    }
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0; i<n; i++) {
            if(!(countDigit(nums[i]) & 1)) cnt++;
        }   
        return cnt;
    }