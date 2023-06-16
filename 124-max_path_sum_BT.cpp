
class Solution {
    public:
    int maxPath(TreeNode* node, int &maxi) {
        if(node == NULL) return 0;
        
        int leftSum = max(0, maxPath(node->left, maxi)); // max(0, call) to deal with negative numbers
        int rightSum = max(0, maxPath(node->right, maxi));
        
        maxi = max(maxi, leftSum + rightSum + node->val);
        
        return max(leftSum, rightSum) + node->val;
    }
    
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPath(root, maxi);
        return maxi;
    }
};