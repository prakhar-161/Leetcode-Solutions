class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> pq;
        for(auto it : points) {
            pq.push({ it[0]*it[0] + it[1]*it[1], it });
            if(pq.size() > k) pq.pop();  // basically, min-heap so reverse operation for max-heap
        }
        
        int i = 0;
        vector<vector<int>> ans;
        while(i < k) {
            ans.push_back(pq.top().second);
            pq.pop();
            i++;
        }
        
        return ans;
    }
};