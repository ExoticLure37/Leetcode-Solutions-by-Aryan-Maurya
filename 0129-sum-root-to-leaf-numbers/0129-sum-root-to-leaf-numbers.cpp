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
    long long sum=0;
    int solve(TreeNode* root,long long temp)
    {
        if(!root)   return 0;
        temp=(temp*10)+root->val;
        if(root->left==NULL && root->right==NULL)   return sum+=temp;
        long long left = solve(root->left,temp);
        long long right = solve(root->right,temp);
        
        return left+right;
    }
    int sumNumbers(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        if(!root)   return 0;
        long long res = solve(root,0ll);
        return sum;
    }
};