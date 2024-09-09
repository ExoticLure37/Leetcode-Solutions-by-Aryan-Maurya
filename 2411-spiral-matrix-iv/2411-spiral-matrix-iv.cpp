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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<int> a;
        while(head!=NULL)
        {
            a.push_back(head->val);
            head=head->next;
        }

        vector<vector<int> > ans(m,vector<int> (n,-1));
        int t=0,l=0,b=m-1,r=n-1,k=0;
        int fl=1;
        while(l<=r && t<=b)
        {
            for(int i=l;i<=r;i++)
            {
                if(k==a.size())
                {
                    fl=0;
                    break;
                }
                ans[t][i]=a[k++];
            }
            t++;
            for(int i=t;i<=b;i++)
            {
                if(k==a.size())
                {
                    fl=0;
                    break;
                }
                ans[i][r]=a[k++];
            }
            r--;
            for(int i=r;i>=l;i--)
            {
                if(k==a.size())
                {
                    fl=0;
                    break;
                }
                ans[b][i]=a[k++];
            }
            b--;
            for(int i=b;i>=t;i--)
            {
                if(k==a.size())
                {
                    fl=0;
                    break;
                }
                ans[i][l]=a[k++];
            }
            l++;
            if(fl==0)   break;
        }
        return  ans;
    }
};