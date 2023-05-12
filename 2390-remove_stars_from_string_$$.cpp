// Approach - 1
// Naive
class Solution {
public:
    string removeStars(string s) {
        string ans = "";
        stack<char> st;
        for(int i=0; i<s.length(); i++) {
            st.push(s[i]); 
        }
        
        int cnt = 0;
        while(!st.empty()) {
            if(st.top() == '*') {
                cnt++;
                st.pop();
            }
            else {
                while(cnt!=0) {
                    st.pop();
                    cnt=cnt-1;
                } 
                int ele = st.top();
                st.pop();
                ans.push_back(ele);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// Approach - 2
// Better and no runtime error
class Solution {
public:
    string removeStars(string s) {
        string ans = "";
        stack<char> st;
        for(int i=0; i<s.length(); i++) {
            if(s[i] != '*') {
                st.push(s[i]);
            } 
            else {
                st.pop();
            }
        }
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// Approach - 3
// Most optimal
class Solution {
public:
    string removeStars(string s) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        int n = s.size();
        string ans = "";
        for(int i = 0; i < n; i++){
            if(s[i] == '*') ans.pop_back();
            else ans+=s[i];
        }
        return ans;
    }
};