class Solution {
public:
    int n, m;
    vector<vector<int>> dp;
    
    int solve(int idx, int i, vector<int> &nums, vector<int> &mul) {
        if (idx == m) return 0;
        if (dp[idx][i] != INT_MIN) return dp[idx][i];

        int j = n - 1 - (idx - i);

        int left = nums[i] * mul[idx] + solve(idx + 1, i + 1, nums, mul);
        int right = nums[j] * mul[idx] + solve(idx + 1, i, nums, mul);

        return dp[idx][i] = max(left, right);
    }
    
    int maximumScore(vector<int>& nums, vector<int>& mul) {
        n = nums.size();
        m = mul.size();

        dp.resize(m, vector<int>(m, INT_MIN));

        return solve(0, 0, nums, mul);
    }
};
