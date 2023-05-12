#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mpp;
        for(int i=0; i<n; i++) {
            if(nums[i] % 2 == 0) {
                mpp[nums[i]]++;
            }
        }
        
        int cnt = 0;
        int maxi = INT_MIN;
        int ele = -1;
        for(auto it : mpp) {
            cnt = it.second;
            if(cnt > maxi) {
                maxi = cnt;
                ele = it.first;
            }
        }
        
        return ele;
    }
};