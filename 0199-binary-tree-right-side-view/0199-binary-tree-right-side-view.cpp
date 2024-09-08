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
    vector<int> rightSideView(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<int> ans;
        if(!root)   return ans;
        ans.push_back(root->val);
        queue<TreeNode*> q;
        q.push(root);
        while(q.size())
        {
            int size = q.size();
            vector<int> temp;
            while(size--)
            {
                auto node = q.front();
                q.pop();
                if(node->left!=NULL)
                {
                    q.push(node->left);
                    temp.push_back(node->left->val);
                }
                if(node->right!=NULL)
                {
                    q.push(node->right);
                    temp.push_back(node->right->val);
                }
            }
            if(temp.size()>0)   ans.push_back(temp.back());
        }
        return ans;
    }
};