class Solution {
public:
    int n;
    bool solve(vector<int> &nums){
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1])   return 0;
        }
        return 1;
    }
    bool checkPossibility(vector<int>& nums) {
        n=nums.size();
        int prev=-1e5;
        for(int i=0;i<n;i++){
            int c=nums[i];
            nums[i]=prev;
            bool chk=solve(nums);
            if(chk==true)   return true;
            nums[i]=c;
            prev=nums[i];
        }
        return false;
    }
};