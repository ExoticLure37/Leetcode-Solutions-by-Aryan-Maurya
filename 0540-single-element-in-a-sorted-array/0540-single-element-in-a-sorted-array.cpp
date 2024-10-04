class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        // if(r)
        while(l<=r){
            int mid=l+(r-l)/2;
            if(mid&1)   mid--;
            if(mid+1<nums.size() && nums[mid]==nums[mid+1])
            {
                l=mid+2;
            }
            else
            {
                r=mid-1;
            }
        }
        return nums[l];
    }
};