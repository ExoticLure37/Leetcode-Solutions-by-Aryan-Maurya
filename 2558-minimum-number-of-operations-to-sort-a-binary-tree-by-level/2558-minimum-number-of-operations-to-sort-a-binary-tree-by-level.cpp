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
    int minSwap(vector<int> nums){
        int cnt=0;
        int n=nums.size();
        vector<pair<int,int> > tmp;
        for(int i=0;i<n;i++){
            tmp.push_back({nums[i],i});
        }
        sort(tmp.begin(),tmp.end());
        for(int i=0;i<n;i++){
            if(tmp[i].second==i)    continue;
            else{
                swap(tmp[tmp[i].second],tmp[i]);
                cnt++;
                i--;
            }
        }
        return cnt;
    }
    int minimumOperations(TreeNode* root) {
        int res=0;
        if(root==nullptr)   return res;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            int size=q.size();
            vector<int> t;
            for(int i=0;i<size;i++){
                auto node=q.front();
                q.pop();
                t.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            res+=minSwap(t);
        }
        return res;
    }
};