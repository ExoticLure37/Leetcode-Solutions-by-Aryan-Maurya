using ll=long long;
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        ll n=nums.size();
        
        vector<ll> preMax;
        vector<ll> sufMax;

        preMax.push_back(0);
        int mx=nums[0];
        for(int i=1;i+1<n;i++){
            preMax.push_back(mx);
            mx=max(mx,nums[i]);
        }
        preMax.push_back(0);

        sufMax.push_back(0);
        mx=nums[n-1];
        for(int i=n-2;i>0;i--){
            sufMax.push_back(mx);
            mx=max(mx,nums[i]);
        }

        sufMax.push_back(0);
        reverse(sufMax.begin(),sufMax.end());

        ll res=0;

        for(int i=1;i<n-1;i++){
            ll val = (preMax[i]-nums[i])*sufMax[i];
            res=max(res,val);
        }

        return res; 


    }
};