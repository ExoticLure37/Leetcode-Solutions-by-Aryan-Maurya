class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int mB) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<int> res;
        int n=nums.size();
        int num=0,i=0;
        res.resize(n);
        while(mB--){
            num+=(pow(2,i));
            i++;
        }
        vector<int> xr(n);
        xr[0]=(nums[0]);
        for(int i=1;i<n;i++){
            int p=xr[i-1]^nums[i];
            xr[i]=p;
        }
        for(int i=0;i<n;i++){
            res[i]=xr[i]^num;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};