class Solution {
public:
    void rsv(TreeNode* node, int level, vector<int> &ds) {
        if(node == NULL) return;
        if(level == ds.size()) ds.push_back(node->val);
        
        rsv(node->right, level+1, ds);
        rsv(node->left, level+1, ds);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ds;
        rsv(root, 0, ds);
        return ds;
    }
};