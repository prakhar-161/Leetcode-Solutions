class Solution {
public:
    int dfs(int row, int col, int ans, int delrow[], int delcol[], vector<vector<int>>& grid, vector<vector<int>> &vis)     {
        ans += grid[row][col];
        vis[row][col] = 1;
        
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i=0; i<4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol] != 0) {
                return ans + dfs(nrow, ncol, ans, delrow, delcol, grid, vis);
            }
            return 0;
        }
        return 0;
    }
    
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> vis(m, vector<int> (n, 0));
        
        int maxi = 0;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] != 0 && !vis[i][j]) {
                    maxi = max(maxi, dfs(i, j, 0, delrow, delcol, grid, vis));
                }
            }
        }
        return maxi;
    }
};


// Praty
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define ff first
#define ss second
#define u_map unordered_map
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define MOD 1e9+7
#define pb push_back
#define MP make_pair
#define f(i,a,b) for (int i = a; i <= b; i++)


int AreaOfIsland(vector<vector<int>> &grid, int i, int j){
    if( i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] != 0){
        int tmp = grid[i][j];
        grid[i][j] = 0;
        return tmp + AreaOfIsland(grid, i+1, j) + AreaOfIsland(grid, i-1, j) + AreaOfIsland(grid, i, j-1) + AreaOfIsland(grid, i, j+1);
    }
    return 0;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int x;
            cin >> x;
            grid[i][j] = x;
        }
    }
    int max_vol = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(grid[i][j] != 0)max_vol = max(max_vol, AreaOfIsland(grid, i, j));

    cout << max_vol << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}