class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n=nums.size();

        int sum=0,tmp=0;
        int prev=-1;

        for(int i=0;i<n;i++){
            if(nums[i] > prev){
                tmp+=nums[i];
                prev = nums[i];
            }    
            else{
                tmp = nums[i];
                prev = nums[i];
            }
            sum=max(sum,tmp);
        }

        return sum;
    }
};