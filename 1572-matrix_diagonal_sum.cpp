// Approach - 1
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum1 = 0, sum2 = 0, sum = 0;
        if(n % 2 != 0) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    if(i == j) sum1 += mat[i][j];
                    if(i == n - j - 1) sum2 += mat[i][j];
                }
            }
            sum = sum1 + sum2 - mat[n/2][n/2];
        }
        else {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    if(i == j) sum1 += mat[i][j];
                    if(i == n - j - 1) sum2 += mat[i][j];
                }
            }
            sum = sum1 + sum2;
        }
        return sum;
    }
};

// Approach - 2
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += mat[i][i]; 
            if (i != n - i - 1) { 
                sum += mat[i][n - i - 1]; 
            }
        }
        return sum;
    }
};