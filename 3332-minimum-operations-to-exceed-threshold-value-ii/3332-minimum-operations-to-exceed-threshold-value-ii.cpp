using ll = long long;
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        priority_queue<ll,vector<ll> ,greater<ll> > pq;

        ll n=nums.size();

        for(ll i=0;i<n;i++)    pq.push(nums[i]);

        ll op=0;

        while(pq.size()>=2){
            if(pq.top()>=k){
                break;
            }

            ll x=pq.top();pq.pop();
            ll y=pq.top();pq.pop();
            ll val=min(x,y)*2*1ll+max(x,y);

            // cout<<"x="<<x<<" y="<<y<<" val="<<val<<endl;
            pq.push(val);
            op++;
        }

        return op;
    }
};