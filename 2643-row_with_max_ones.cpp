#include<bits/stdc++.h>
using namespace std;

// Given a m x n binary matrix mat, find the 0-indexed position of the row that contains the maximum count of ones, and the number of ones in that row.
// In case there are multiple rows that have the maximum count of ones, the row with the smallest row number should be selected.
// Return an array containing the index of the row, and the number of ones in it.

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int maxi = 0, ind = 0, temp = 0;
        for(int i=0; i<m; i++) {
            int cnt = 0;
            for(int j=0; j<n; j++) {
                if(mat[i][j] == 1) cnt++;
            }
            temp = maxi;
            maxi = max(maxi, cnt);
            if(temp != maxi) ind = i;
        }
        
        return {ind, maxi};
    }
};