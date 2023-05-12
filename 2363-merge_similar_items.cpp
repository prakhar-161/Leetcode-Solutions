// You are given two 2D integer arrays, items1 and items2, representing two sets of items. 
// Each array items has the following properties:
// items[i] = [valuei, weighti] where valuei represents the value and weighti represents the weight of the ith item.
// The value of each item in items is unique.
// Return a 2D integer array ret where ret[i] = [valuei, weighti], with weighti being the sum of weights of all items with value valuei.
// Note: ret should be returned in ascending order by value.

class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int, int> mp;
        for(int i=0; i<items1.size(); i++) {
            mp[items1[i][0]] = items1[i][1];
        }
        for(int i=0; i<items2.size(); i++) {
            if(mp.find(items2[i][0]) != mp.end()) {
                mp[items2[i][0]] += items2[i][1];
            }
            else {
                mp[items2[i][0]] = items2[i][1];
            }
        }
        
        vector<vector<int>> ans;
        for(auto it : mp) {
            ans.push_back({it.first, it.second});
        }
        return ans;
    }
};