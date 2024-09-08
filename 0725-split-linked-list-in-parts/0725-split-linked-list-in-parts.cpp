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

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        ListNode* temp = head;
        int l=0;
        while(temp!=NULL)
        {
            a.push_back(temp->val);
            l++;
            temp=temp->next;
        }

        auto [q,r] = div(a.size(),k);

        vector<vector<int> > ans;
        int d=0,i=0,n=a.size();
        while(d<n)
        {
            int f=0;
            vector<int> tp;
            while(f<q)
            {
                tp.push_back(a[d++]);
                f++;
            }
            if(r>0)
            {
                tp.push_back(a[d++]);
                r--;
            }
            ans.push_back(tp);
            tp.clear();
        }

        a.clear();
        vector<ListNode*> res;
        for(auto vec:ans)
        {
            ListNode* f=new ListNode(0);
            ListNode* s=NULL;
            s=f;
            for(auto data : vec)
            {
                ListNode* newNode = new ListNode(data);
                f->next = newNode;
                f=f->next;
            }
            res.push_back(s->next);
        }
        while(res.size()<k)
        {
            res.push_back({});
        }
        return res;
    }
};
    