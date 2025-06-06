/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
    root->val = 0;
    queue<TreeNode*> q;  q.push(root);
    while(!q.empty()){
        int n = q.size(), sum = 0;
        vector<TreeNode*> buf;
        while(n--){
            TreeNode* node = q.front(); q.pop();
            buf.push_back(node);
            if(node->left) { q.push(node->left); sum += node->left->val; }
            if(node->right){ q.push(node->right); sum += node->right->val; }
        }
        for(auto node: buf){
            int  t = sum;
            if(node->left)  t -= node->left->val;
            if(node->right) t -= node->right->val;
            if(node->left)  node->left->val = t;
            if(node->right) node->right->val = t;
        }
    }
    return root;
}
};