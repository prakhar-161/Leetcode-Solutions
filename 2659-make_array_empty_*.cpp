
// The following code gave TLE, passed 505/514 cases
// Time complexity high
class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        long long int count = 0;
        deque<int> dq;
        priority_queue<int, vector<int>, greater<int> > pq;
        for(int i=0; i<nums.size(); i++) {
            dq.push_back(nums[i]);
            pq.push(nums[i]);
        }
        
        while(!dq.empty()) {
            if(dq.front() == pq.top()) {
                dq.pop_front();
                pq.pop();
            }
            else {
                int ele = dq.front();
                dq.pop_front();
                dq.push_back(ele);
            }
            count++;
        }
        
        return count;
    }
};


// Optimised code
