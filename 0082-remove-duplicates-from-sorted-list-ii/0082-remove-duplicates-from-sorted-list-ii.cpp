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
    ListNode* deleteDuplicates(ListNode* head) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        map<int,int> mp;
        ListNode* temp = head;
        while(temp!=NULL)
        {
            mp[temp->val]++;
            temp=temp->next;
        }

        ListNode* f=new ListNode(-1);
        ListNode* s= NULL;
        s=f;
        for(auto it:mp)
        {
            if(it.second>1) continue;
            ListNode* node = new ListNode(it.first);
            f->next=node;
            f=f->next;
        }
        return s->next;
    }
};