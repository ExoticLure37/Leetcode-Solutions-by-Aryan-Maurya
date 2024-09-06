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
    ListNode* removeNodes(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> a;
        ListNode* temp = head;
        while(temp!=NULL)
        {
            a.push_back(temp->val);
            temp=temp->next;
        }
        int n=a.size();
        priority_queue<int> pq;
        for(int i=n-1;i>=0;i--)
        {
            int val = a[i];
            if(!pq.empty() && pq.top()>val)
            {
                a[i]=-1;
            }
            else
            {
                pq.push(val);
            }
        }
        // for(auto i:a)   cout << i << " ";
        ListNode* f=new ListNode(-1);
        ListNode* s = NULL;
        s=f;
        for(auto val:a)
        {
            if(val==-1) continue;
            ListNode* tmp = new ListNode(val);
            f->next=tmp;
            f=f->next;
        }
        return s->next;
    }
};