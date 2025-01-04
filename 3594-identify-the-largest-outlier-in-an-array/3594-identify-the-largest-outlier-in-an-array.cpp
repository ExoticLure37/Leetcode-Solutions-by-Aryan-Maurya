class Solution {
public:
    map<int,int> mp;
    int getLargestOutlier(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        for(auto c:nums)    mp[c]++;
        int sum=accumulate(nums.begin(),nums.end(),0);
        int res=-1001;
        for(int i=0;i<nums.size();i++){
            int g=nums[i];
            int left=sum-g;         //removing outlie,sum must be even
            if(left%2==0){
                // cout<<"left="<<left<<" k=";
                int k=left/2;
                // cout<<k<<" mp[k]="<<mp[k]<<endl;
                if(mp[k]>1) res=max(res,nums[i]);
                else if(mp[k]==1 && k!=nums[i]) res=max(res,nums[i]);
            }
        }
        return res;
    }  
};