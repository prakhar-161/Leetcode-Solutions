class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int pre = 0, maxi = 0;
        for(int i=0; i<gain.size(); i++) {
            pre += gain[i];
            maxi = max(maxi, pre);
        }
        return maxi;
    }
};

// prefix sum concept