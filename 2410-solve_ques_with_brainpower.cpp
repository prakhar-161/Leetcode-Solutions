// Memoization
class Solution {
public:
    // (ind) -> linear DP
    long long solve(int ind, int n, vector<vector<int>>& questions, vector<long long> &dp) {
        // if(ind == n-1) return questions[n-1][0];
        if(ind >= n) return 0;
        
        if(dp[ind] != -1) return dp[ind];
        
        long long pick = questions[ind][0] + solve(ind + questions[ind][1] + 1, n, questions, dp);
        long long notpick = solve(ind + 1, n, questions, dp);
        
        return dp[ind] = max(pick, notpick);
    }
    
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, -1);
        return solve(0, n, questions, dp);
    }
};

// Tabulation
#define ll long long
class Solution {
public:

    ll solveTab(vector<vector<int>>& q)  {
        int n = q.size();
        vector<ll> dp(n+1 , 0);
        for(int i=n-1; i>=0; i--)    {
            int nextIndex= i+1+q[i][1]; 
            long long include   = q[i][0] + ( (nextIndex<=n) ? dp[nextIndex] : 0 );
            long long exclude = dp[i+1];
            dp[i]= max(include,exclude);
        }
        return dp[0];
    }

    long long mostPoints(vector<vector<int>>& questions) {
        return solveTab(questions);
    }
};