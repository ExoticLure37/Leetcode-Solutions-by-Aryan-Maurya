using ll=long long;
class Solution {
public:
    ll maximumTripletValue(vector<int>& nums) {
        ll n=nums.size();
        ll res=0;

        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    ll val=(nums[i]-nums[j]+1ll-1ll)*1ll*nums[k];
                    // cout<<"val="<<val<<endl;
                    res=max(res,val);
                }
            }
        }    

        return res;
    }
};