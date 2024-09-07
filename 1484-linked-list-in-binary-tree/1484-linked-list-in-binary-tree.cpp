/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool solve(ListNode * head ,TreeNode* root)
    {
        if(root==nullptr && head!=nullptr)  return false;
        if(head==nullptr) return true;
        if(head->val == root->val)
        {
            return solve(head->next,root->right) || solve(head->next ,root->left);
        }
        return false;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        if(root==nullptr && head!=nullptr)  return false;
        // if(root!=nullptr && head==nullptr)  return true;

        bool ans = solve(head,root) || isSubPath(head,root->left) || isSubPath(head,root->right);

        return ans;
    }
};