class Solution {
public:
    int n, m;
    vector<vector<int> > dp;

    int solve(int idx, int i ,vector<int> &nums, vector<int> &mul) {
        if (idx == m || i==n) {
            return 0;
        }

        if(dp[i][idx]!=-1)  return dp[i][idx];

        int j=n-1-idx+i;

        int front = nums[i];
        int back = nums[j];

        int x = front * mul[idx];
        int y = back * mul[idx];

        int a = INT_MIN, b = INT_MIN;

        a = solve(idx + 1, i + 1, nums, mul) + x;
        b = solve(idx + 1, i, nums, mul) + y;

        return dp[i][idx]=max(a, b);
    }

    int maximumScore(vector<int>& nums, vector<int>& mul) {
        n = nums.size();
        m = mul.size();

        dp.resize(m,vector<int> (m,-1));

        return solve(0, 0, nums, mul);
    }
};
