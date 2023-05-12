#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> count;
        for(int i=0; i<arr.size(); i++) {
            count[arr[i]]++;
        }
        
        unordered_set<int> countSet;
        for(auto [key, value] : count) {
            countSet.insert(value);
        }

        return (countSet.size() == count.size());
    }
};

// TC -> O(N)
// SC -> O(N)