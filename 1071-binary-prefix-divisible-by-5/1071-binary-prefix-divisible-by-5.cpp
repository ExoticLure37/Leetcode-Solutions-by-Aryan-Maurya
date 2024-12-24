class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool > res;
        int n=nums.size();
        long long tmp=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1)    tmp=(tmp<<1)|1;
            else    tmp=tmp<<1;
            tmp%=5;
            // cout<<"tmp="<<tmp<<endl;
            if(tmp%5==0)    res.push_back(true);
            else    res.push_back(0);
        }
        return res;
    }
};