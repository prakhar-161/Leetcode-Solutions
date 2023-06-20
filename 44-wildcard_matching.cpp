class Solution {
public:
    bool isMatch(string s, string p) {
        int m = p.length();
        int n = s.length();
        vector<vector<bool>> dp(m+1, vector<bool> (n+1, false));
    
        // base case
        dp[0][0] = true;
        for(int j=1; j<=n; j++) dp[0][j] = false;
        for(int i=1; i<=m; i++) {
            bool flag = true;
            for(int k=1; k<=i; k++) {
                if(p[k-1] != '*') {
                    flag = false;
                    break;
                }
            }
            dp[i][0] = flag;
        }

        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if(p[i-1] == s[j-1] || p[i-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                } 
                else if(p[i-1] == '*') {
                    dp[i][j] = dp[i-1][j] | dp[i][j-1];
                }
                else {
                    dp[i][j] = false;
                }
            }
        }
        return dp[m][n];
    }   
};

// prefer memoization solution to understand

// Memoization
class Solution {
public:
    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
        // base case
        if(i == 0 && j == 0) return true;
        if(i == 0 && j > 0) return false;
        if(j == 0 && i > 0) {
            for(int k=1; k<=i; k++) {
                if(p[k-1] != '*') return false;
            }
            return true;
        }
        
        if(dp[i][j] != -1) return dp[i][j];

        if(p[i-1] == s[j-1] || p[i-1] == '?') {
            return dp[i][j] = solve(i-1, j-1, s, p, dp);
        }
        else if(p[i-1] == '*') {
            return dp[i][j] = (solve(i-1, j, s, p, dp) | solve(i, j-1, s, p, dp));
        }
        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int m = p.length();
        int n = s.length();
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        return solve(m, n, s, p, dp);
    }
};

// p -> m (i)
// s -> n (j)