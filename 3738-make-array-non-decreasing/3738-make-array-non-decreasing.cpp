class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int mx=0;

        int len=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]<mx){

            }
            else{
                mx=max(mx,nums[i]);
                len++;
            }
        }

        return len;
    }
};