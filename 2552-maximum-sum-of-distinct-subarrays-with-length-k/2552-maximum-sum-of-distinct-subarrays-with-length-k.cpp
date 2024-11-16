class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0,r=0;
        deque<int> arr;
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
            // cout<<"res="<<res<<endl;
        while(r<n){
            // for(auto c:mp)  cout<<c.first<<" ";
            // cout<<endl;
            mp[nums[l]]--;
            if(mp[nums[l]]==0)  mp.erase(nums[l]);
            sum-=nums[l];
            l++;
            mp[nums[r]]++;
            sum+=nums[r];
            // for(auto c:mp)  cout<<c.first<<" ";
            // cout<<endl;
            if(mp.size()==k)    res=max(res,sum);
            // cout<<"res="<<res<<endl;
            r++;
        }
        return res;
    }
};