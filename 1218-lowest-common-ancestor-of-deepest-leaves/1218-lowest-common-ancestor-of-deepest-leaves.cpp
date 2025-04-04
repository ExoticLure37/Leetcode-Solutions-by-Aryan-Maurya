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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if (root == NULL || root == p || root == q) {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left == NULL) {
            return right;
        }
        else if(right == NULL) {
            return left;
        }
        else {
            return root;
        }
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        map<TreeNode*,int> depth;

        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(q.size()){
            auto [node,d]=q.front();
            q.pop();
            depth[node]=d;
            if(node->left!=NULL)    q.push({node->left,d+1});
            if(node->right!=NULL)    q.push({node->right,d+1});
        }

        int D=0;
        for(auto c:depth){
            D=max(D,c.second);
        }

        vector<TreeNode*> node;

        for(auto c:depth){
            if(c.second==D) node.push_back(c.first);
        }

        if(node.size()==0)  return root;

        if(node.size()==1)  return lowestCommonAncestor(root,node[0],NULL);

        TreeNode* res=NULL;

        for(int i=0;i<node.size();i++){
            res=lowestCommonAncestor(root,res,node[i]);
        }

        return res;

    }
};