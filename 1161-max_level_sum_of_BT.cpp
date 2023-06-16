class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        int maxi = INT_MIN, ans = 0;
        while(!q.empty()) {
            int size = q.size();
            // vector<int> level;
            int l = q.front().second;
            int sum = 0;
            for(int i=0; i<size; i++) {
                TreeNode* node = q.front().first;
                q.pop();
                sum += node->val;
                if(node->left) {
                    q.push({node->left, l+1});
                }
                if(node->right) {
                    q.push({node->right, l+1});
                }
            }
            if(sum > maxi) {
                maxi = sum;
                ans = l;
            }
        }
        return ans;
    }
};