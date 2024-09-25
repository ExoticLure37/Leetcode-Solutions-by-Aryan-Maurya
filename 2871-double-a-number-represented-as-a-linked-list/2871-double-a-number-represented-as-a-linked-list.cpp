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
    ListNode* doubleIt(ListNode* l1) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<int> num1;
        ListNode* temp = l1;
        while(temp!=NULL)
        {
            num1.push_back(temp->val);
            temp=temp->next;
        }
        reverse(num1.begin(),num1.end());
        int cy=0;
        ListNode* f=new ListNode(-1);
        ListNode* s=NULL;
        s=f;
        vector<int> ans;
        for(int i=0;i<num1.size();i++)
        {
            int val = (num1[i]*2)+cy;
            cy=val/10;
            val%=10;
            ans.push_back(val);
        }
        if(cy)  ans.push_back(cy);
        reverse(ans.begin(),ans.end());
        for(auto c:ans)
        {
            ListNode* newnode = new ListNode(c);
            f->next = newnode;
            f=f->next;
            // cout << c<<" ";
        }
        return s->next;
    }
};