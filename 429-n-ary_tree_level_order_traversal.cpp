class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            vector<int> treeLevel;
            for(int i=0; i<size; i++) {
                Node* node = q.front();
                q.pop();
                for(auto it : node->children) {
                    q.push(it);
                }
                treeLevel.push_back(node->val);
            }
            ans.push_back(treeLevel);
        }
        return ans;
    }
};