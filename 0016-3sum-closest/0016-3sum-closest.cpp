class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n=nums.size();
        if(n<3){return 0;}
        sort(nums.begin(),nums.end());
        int ans=0;
        int minus = INT_MAX;
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1])   continue;
            int j=i+1,k=n-1;
            while(j<k)
            {
                int sum = (nums[i]+nums[j]+nums[k]);
                int diff = abs(sum-target);
                if(sum==target) return sum;
                if(diff<minus){
                    ans = sum;
                    minus = diff;
                }
                if(sum<target)  j++;
                else k--;
            }
        }
        return ans;
    }
};