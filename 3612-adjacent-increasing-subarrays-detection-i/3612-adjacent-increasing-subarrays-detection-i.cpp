class Solution {
public:
    bool ok(vector<int> &nums,int s,int k){
        for(int i=s;i+1<s+k;i++){
            if(nums[i]>=nums[i+1])  return false;
        }
        return true;
    }
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<=nums.size()-2*k;i++){
            if(ok(nums,i,k)&&ok(nums,i+k,k))    return true;
        }
        return false;
    }
};