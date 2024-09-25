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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<int> num1,num2;
        ListNode* temp = l1;
        while(temp!=NULL)
        {
            num1.push_back(temp->val);
            temp=temp->next;
        }
        temp=l2;
        while(temp!=NULL)
        {
            num2.push_back(temp->val);
            temp=temp->next;
        }

        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        int cy=0;
        ListNode* f=new ListNode(-1);
        ListNode* s=NULL;
        s=f;
        int i=0;
        vector<int> ans;
        for(i=0;i<min(num1.size(),num2.size());i++)
        {
            int val = num1[i]+num2[i]+cy;
            cy=val/10;
            val%=10;
            ans.push_back(val);
        }
        while(i<num1.size())
        {
            int val = num1[i]+cy;
            cy=val/10;
            val%=10;
            ans.push_back(val);
            i++;
        }
        while(i<num2.size())
        {
            int val = num2[i]+cy;
            cy=val/10;
            val%=10;
            ans.push_back(val);
            i++;
        }
        if(cy)  ans.push_back(cy);
        reverse(ans.begin(),ans.end());
        for(auto c:ans)
        {
            ListNode* newnode = new ListNode(c);
            f->next = newnode;
            f=f->next;
        }
        return s->next;
    }
};