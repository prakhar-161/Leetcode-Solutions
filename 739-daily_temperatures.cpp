// logic similar to stock span problem i.e of stack<pair<int, int>> st
// next greater to right

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // nearest greater to right case
        // consecutive smaller or equal to after it
        int n = temperatures.size();
        stack<pair<int, int>> st;
        vector<int> ans;      // firstly it stores ngr index
        for(int i=n-1; i>=0; i--) {
            if(st.empty()) {
                ans.push_back(0);
            }
            else if(!st.empty() && st.top().first <= temperatures[i]) {
                while(!st.empty() && st.top().first <= temperatures[i]) {
                    st.pop();
                }
                if(st.empty()) {
                    ans.push_back(0);
                }
                else {
                    ans.push_back(st.top().second);
                }
            }
            else if(!st.empty() && temperatures[i] < st.top().first) {
                ans.push_back(st.top().second);
            }
            
            st.push({temperatures[i], i});
        }
        
        reverse(ans.begin(), ans.end());
        for(int i=0; i<ans.size()-1; i++) {
            ans[i] = ans[i] - i;
            if(ans[i] < 0) ans[i] = 0;
        }
        return ans;
    }
};

