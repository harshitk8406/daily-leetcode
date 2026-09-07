class Solution {
public:
    int distinctSubseqII(string s) {
        int mod = 1e9+7;
        long long dp[26] = {0};
        long long ans = 0;

        for (auto ch : s){
            int c = ch - 'a';
            long long x = (ans + 1) % mod;
            ans = (ans + x - dp[c] + mod) % mod;
            dp[c] = x;
        }
        return ans;
    }
};