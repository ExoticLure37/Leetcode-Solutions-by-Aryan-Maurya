class Solution {
public:
    int n;
    int dp[1001][1001][3];
    int solve(int idx, vector<int> &nums, int sign, int prev) {
        if (idx == n) return 0;

        if(dp[idx][prev+1][sign+1]!=-1) return dp[idx][prev+1][sign+1];

        int include = 0, exclude = 0;
        if (prev == -1) {
            include = 1 + solve(idx + 1, nums, 0, idx);  
        } else {
            int d = nums[idx] - nums[prev];
            if ((sign == 0 && d != 0) || (sign < 0 && d > 0) || (sign > 0 && d < 0)) {
                include = 1 + solve(idx + 1, nums, d > 0 ? 1 : -1, idx);
            }
        }

        exclude = solve(idx + 1, nums, sign, prev);
        return dp[idx][prev+1][sign+1]=max(include, exclude);
    }

    int wiggleMaxLength(vector<int>& nums) {
        n = nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(0, nums, 0, -1);
    }
};
