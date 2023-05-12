// Given a string s, sort it in decreasing order based on the frequency of the characters. 
// The frequency of a character is the number of times it appears in the string.
// Return the sorted string. If there are multiple answers, return any of them.

// We use PRIORITY QUEUES here

class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mpp;
        for(int i=0; i<s.length(); i++) mpp[s[i]]++;

        priority_queue<pair<int, char>> pq;
        for(auto it : mpp) {
            pq.push({it.second, it.first});
        } 

        string ans = "";
        while(!pq.empty()) {
            int cnt = pq.top().first;
            while(cnt--) {
                ans += pq.top().second;
            }
            pq.pop();
        }
        return ans;
    }
};