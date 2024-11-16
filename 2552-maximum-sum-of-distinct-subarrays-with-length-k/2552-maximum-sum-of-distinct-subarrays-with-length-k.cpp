class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n=nums.size();
        int l=0,r=0;
        map<int,int> mp;
        long long sum=0;
        while(r<k){
            mp[nums[r]]++;
            sum+=nums[r];
            r++;
        }
        long long res=0;
        if(mp.size()==k) res=max(res,sum);
        else    res=max(res,0ll);
        while(r<n){
            mp[nums[l]]--;
            if(mp[nums[l]]==0)  mp.erase(nums[l]);
            sum-=nums[l];
            l++;
            mp[nums[r]]++;
            sum+=nums[r];
            if(mp.size()==k)    res=max(res,sum);
            r++;
        }
        return res;
    }
};