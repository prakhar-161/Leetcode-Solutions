class Solution {
public:
    bool isVowel(char c) {
        char t = tolower(c);
        return t == 'a' or t == 'e' or t=='i' or t=='o' or t=='u';
    }
    
    string reverseVowels(string s) {
        stack<char> st;
        for(auto &c : s) {
            if(isVowel(c)) {
                st.push(c);
            }
        }
        
        for(auto &c : s) {
            if(isVowel(c)) {
                c = st.top();
                st.pop();
            }
        }
        
        return s;
    }
};