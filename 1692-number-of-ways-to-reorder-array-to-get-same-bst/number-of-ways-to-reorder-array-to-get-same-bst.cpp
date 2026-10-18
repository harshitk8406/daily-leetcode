class Solution {
public:
    int mod = 1e9 + 7;

    int res(int n, int k) {
        if (k > n / 2)
            k = n - k;

        vector<int> dp(k + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = min(i, k); j >= 1; j--) {
                dp[j] = ((long long)dp[j] + dp[j - 1]) % mod;
            }
        }

        return dp[k];
    }

    long long solve(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2)
            return 1;

        vector<int> left, right;
        int root = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] < root)
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }

        long long l = solve(left);
        long long r = solve(right);

        return res(n - 1, left.size()) * l % mod * r % mod;
    }

    int numOfWays(vector<int>& nums) {
        return (solve(nums) - 1 + mod) % mod;
    }
};