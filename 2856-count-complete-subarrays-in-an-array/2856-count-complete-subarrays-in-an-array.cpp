class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n=nums.size();

        set<int> s;
        for(auto c:nums)    s.insert(c);

        int tar=s.size();
        int res=0;

        // for(int i=0;i<n;i++){
        //     unordered_set<int> s;
        //     for(int j=i;j<n;j++){
        //         s.insert(nums[j]);
        //         if(s.size()==tar)   res++;
        //     }
        // }

        int l=0,r=0;
        unordered_map<int,int> mp;
        while(r<n){
            mp[nums[r]]++;
            while(mp.size()==tar){
                res+=n-r;
                mp[nums[l]]--;
                if(mp[nums[l]]==0) mp.erase(nums[l]);
                l++;
            }
            r++;
        }

        return res;
    }
};