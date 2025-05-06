class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int index = nums[i];
            int val = nums[index];
            ans.push_back(val);
        }
        return ans;
    }
};