class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        mp[0]=-1;
        int res=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i]==1?+1:-1;

            if(mp.find(sum)!=mp.end()){
                res=max(res,i-mp[sum]);
                // cout<<"i="<<i<<" mp[sum]="<<mp[sum]<<" res="<<res<<endl;
            }
            else{
                // cout<<"making entry..."<<sum<<" "<<i<<endl;
                mp[sum]=i;
            }
        }

        return res;
    }
};