using ll=long long;
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        ll n=nums.size();

        sort(nums.begin(),nums.end());
        ll res=0;
        
        for(int i=0;i<n;i++){
            ll num=nums[i];
            ll l=i+1,r=n-1;
            ll left=-1;
            while(l<=r){
                ll m=l+(r-l)/2;
                if(nums[m]+num>=lower){
                    r=m-1;
                    left=m;
                }
                else{
                    l=m+1;
                }
            }

            ll right=-1;
            l=i+1,r=n-1;
            while(l<=r){
                ll m=l+(r-l)/2;
                if(nums[m]+num<=upper){
                    l=m+1;
                    right=m;
                }
                else{
                    r=m-1;
                }
            }

            if(left<0 ||right<0)    {}
            else{
                ll p=right-left+1;
                res+=p;
            };
        }

        return res;
    }
};