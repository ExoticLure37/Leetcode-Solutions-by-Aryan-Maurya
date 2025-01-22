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
    int findBottomLeftValue(TreeNode* root) {
        vector<int> tmp;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            int sz=q.size();
            tmp.clear();
            for(int i=0;i<sz;i++){
                auto node=q.front();
                q.pop();
                tmp.push_back(node->val);
                if(node->left)  q.push(node->left);
                if(node->right)  q.push(node->right);
            }
        } 
        return tmp[0];
    }
};