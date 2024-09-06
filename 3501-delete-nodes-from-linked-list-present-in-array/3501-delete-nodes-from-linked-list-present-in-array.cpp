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
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        ListNode* first = new ListNode(-1);
        ListNode* second = NULL;
        second = first;
        vector<int> k;
        set<int> s;
        for(auto i:nums)    s.insert(i);
        ListNode* temp=head;
        while(temp!=NULL)
        {
            if(s.find(temp->val)==s.end()) k.push_back(temp->val);
            temp=temp->next;
        }
        
        for(auto i:k)
        {
            ListNode* l = new ListNode(i);
            first->next = l;
            first = first->next;
        }

        return second->next;
    }
};