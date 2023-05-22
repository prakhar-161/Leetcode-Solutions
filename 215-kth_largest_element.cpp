class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // max-heap
        priority_queue<int> pq;
        for(int i=0; i<nums.size(); i++) {
            pq.push(nums[i]);
        }
        int i = 0;
        while(i < k-1) {
            pq.pop();
            i++;
        }
        
        return pq.top();
    }
};