
class Solution {
public:
    void solve(TreeNode* root,vector<int>& v){
        if(root==NULL) return;
        v.push_back(root->val);
        if(root->left!=NULL) solve(root->left,v);
        if(root->right!=NULL) solve(root->right,v);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        solve(root,v);
        return v;
    }
};
