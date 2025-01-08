class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int s=0,k=0;
        int t=0;
        for(int i=0;i<nums.size();i++){
            t+=nums[i];
            s=max(s,t);
            k=min(k,t);
        }
        cout<<"s="<<s<<" k="<<k<<endl;
        return abs(s)+abs(k);
    }
};