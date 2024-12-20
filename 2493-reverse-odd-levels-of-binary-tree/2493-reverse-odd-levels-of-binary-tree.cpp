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
    TreeNode* solve(TreeNode* left,TreeNode* right,int level){
        if(left==NULL)  return NULL ;
        if(level%2==1 && left && right){
            int tmp=left->val;
            left->val=right->val;
            right->val=tmp;
        }
        TreeNode* l=solve(left->left,right->right,level+1);
        TreeNode* r=solve(left->right,right->left,level+1);
        return NULL;
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root==NULL)  return NULL;
        TreeNode* res= solve(root->left,root->right,1);
        return root;
    }
};