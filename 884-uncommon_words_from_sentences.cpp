#include<bits/stdc++.h>
using namespace std;

// #include<sstream>

// STRING STREAM CONCEPT
// >> - operator used for reading something from the string stream

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> mpp;
        istringstream iss(s1 + " " + s2);
        string word;
        while(iss >> word) {
            mpp[word]++;
        }

        vector<string> ans;
        for(auto it : mpp) {
            if(it.second == 1) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
// TC -> O(N*logN)
// SC -> O(N)