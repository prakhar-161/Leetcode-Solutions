class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        for(auto p : piles) {
            pq.push(p);
        }
        //take the largest pile, pop the largest and push (largest-(floor(largest/2)))
        while(!pq.empty() && k--)
        {
            auto x=pq.top();
            pq.pop();
            x-=floor(x/2);
            pq.push(x);   //important step
        }
        
        long long sum=0;
        while(!pq.empty())
        {   cout<<pq.top()<<" ";
            sum+=pq.top();
            pq.pop();
        }
        return sum;   
    }
};