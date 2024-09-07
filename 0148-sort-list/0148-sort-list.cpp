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
    vector<int> a;
    ListNode* sortList(ListNode* head) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        ListNode* temp = head;
        while(temp!=NULL)
        {
            a.push_back(temp->val);
            temp=temp->next;
        }

        sort(a.begin(),a.end());
        ListNode* f=new ListNode(0);
        ListNode* s=NULL;
        s=f;
        for(auto num:a)
        {
            ListNode *t = new ListNode(num);
            f->next=t;
            f=f->next;
        }
        return s->next;
    }
};