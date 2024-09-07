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
    TreeNode* buildTree(vector<int> &a,int s,int e)
    {
        if(s>=e)    return NULL;
        int mid = (s+e)/2;
        TreeNode* root = new TreeNode(a[mid]);
        root->left = buildTree(a,s,mid);
        root->right = buildTree(a,mid+1,e);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<int> a;
        ListNode* temp = head;
        while(temp!=NULL)
        {
            a.push_back(temp->val);
            temp=temp->next;
        }
        return buildTree(a,0,a.size());
    }
};