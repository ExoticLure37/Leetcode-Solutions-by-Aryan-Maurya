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
    // int hcf(int a,int b){
    //     //a > b
    //     if(a>=b){
    //         if(a%b==0){return b;}
    //         return hcf(b,a%b);
    //     }
    //     else{
    //         if(b%a==0){return a;}
    //         return hcf(a,b%a);
    //     }
    // }
    ListNode* insertGreatestCommonDivisors(ListNode* head){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        ListNode* prev = head;
        ListNode* curr = head;
        while(curr and curr->next){
            prev = curr; 
            curr = curr->next;
            int newVal = __gcd(prev->val,curr->val); 
            ListNode* dummyNode = new ListNode(newVal);
            prev->next = dummyNode;
            dummyNode->next = curr;
        }
        return head;
    }
};