class Solution {
public:
    // nums = [1,1,1,2,2,3], k=2
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for(int i=0; i<nums.size(); i++) {
            mpp[nums[i]]++;
        }
        // 1->3, 2->2, 3->1
        
        // max-heap
        priority_queue<pair<int, int>> pq;
        for(auto it : mpp) {
            pq.push({it.second, it.first});
        }
        // pq -> (3,1) (2,2) (1,3)
        int i = 0;
        vector<int> ans;
        while(i < k) {
            int ele = pq.top().second;
            ans.push_back(ele);
            pq.pop();
            i++;
        }
        return ans;
    }
};