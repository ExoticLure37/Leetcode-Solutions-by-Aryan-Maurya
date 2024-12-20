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
    void solve(TreeNode* left,TreeNode* right,int level){
        if(left==NULL)  return ;
        if(level%2==0 && left && right){
            swap(left->val,right->val);
        }

        solve(left->left,right->right,level+1);
        solve(left->right,right->left,level+1);
        return ;
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root==NULL)  return NULL;
        solve(root->left,root->right,0);
        return root;
    }
};