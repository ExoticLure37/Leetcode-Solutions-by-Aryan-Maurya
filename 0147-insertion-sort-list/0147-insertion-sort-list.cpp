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
    ListNode* insertionSortList(ListNode* head) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<int> a;
        if(head==nullptr)   return head;
        ListNode* temp = head;
        while(temp!=NULL)
        {
            a.push_back(temp->val);
            temp=temp->next;
        }

        sort(a.begin(),a.end());
        ListNode* f=new ListNode(-1);
        ListNode* s=NULL;
        s=f;
        for(auto num : a)
        {
            temp = new ListNode(num);
            f->next = temp;
            f = f->next;
        }
        return s->next;
    }
};