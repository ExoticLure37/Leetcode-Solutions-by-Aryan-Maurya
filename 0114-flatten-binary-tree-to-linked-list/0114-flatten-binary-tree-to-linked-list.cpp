class Solution {
public:
    vector<int> a;  // Vector to store preorder traversal values
    
    void pre(TreeNode* root) {
        if (!root) return;
        a.push_back(root->val);
        pre(root->left);
        pre(root->right);
    }
    
    void flatten(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        if (!root) return;
        pre(root);
        TreeNode* current = root;
        for (int i = 1; i < a.size(); ++i) {
            current->left = nullptr; 
            current->right = new TreeNode(a[i]);  
            current = current->right;  
        }
    }
};
