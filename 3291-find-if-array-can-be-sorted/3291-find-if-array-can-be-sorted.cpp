class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n-i-1;j++){
                if(nums[j]>nums[j+1]){
                    if(__builtin_popcount(nums[j])==__builtin_popcount(nums[j+1])){
                        swap(nums[j],nums[j+1]);
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
};