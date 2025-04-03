class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n=nums.size();

        vector<int > preMax;
        vector<int> sufMin;

        int mx=0;
        for(int i=0;i<n;i++){
            preMax.push_back(mx);
            mx=max(mx,nums[i]);
        }

        int mn=1e5+10;
        for(int i=n-1;i>=0;i--){
            sufMin.push_back(mn);
            mn=min(mn,nums[i]);
        }

        reverse(sufMin.begin(),sufMin.end());

        int res=0;
        for(int i=1;i+1<n;i++){
            if(preMax[i] < nums[i] && nums[i] < sufMin[i]){
                res+=2;
            }
            else if(nums[i-1]<nums[i] && nums[i]<nums[i+1]){
                res+=1;
            }
        }

        return res;

    }
};