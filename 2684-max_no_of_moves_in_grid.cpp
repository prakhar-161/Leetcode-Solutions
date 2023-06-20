// You are given a 0-indexed m x n matrix grid consisting of positive integers.
// You can start at any cell in the first column of the matrix, and traverse the grid in the following way:
// From a cell (row, col), you can move to any of the cells: (row - 1, col + 1), (row, col + 1) and (row + 1, col + 1) such that the value of the cell you move to, should be strictly bigger than the value of the current cell.
// Return the maximum number of moves that you can perform.

class Solution {
public:
    int solve(int i, int j, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp) {
        if(dp[i][j] != -1) return dp[i][j];

        int upright = 0, right = 0, downright = 0;
        if(j+1 < m && i-1 >= 0 && grid[i][j] < grid[i-1][j+1]) {
            upright = 1 + solve(i-1, j+1, n, m, grid, dp);
        }
        if(j+1 < m && grid[i][j] < grid[i][j+1]) {
            right = 1 + solve(i, j+1, n, m, grid, dp);
        }
        if(j+1 < m && i+1 < n && grid[i][j] < grid[i+1][j+1]) {
            downright = 1 + solve(i+1, j+1, n, m, grid, dp);
        }

        return dp[i][j] = max(upright, max(right, downright));
    }

    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int> (m, -1));

        int ans = 0;
        for(int row = 0; row < n; row++) {
            ans = max(ans, solve(row, 0, n, m, grid, dp));
        }

        return ans;
    }
};
// make sure to write the bound conditions first in the if conditions in solve function
// otherwise it will give runtime error