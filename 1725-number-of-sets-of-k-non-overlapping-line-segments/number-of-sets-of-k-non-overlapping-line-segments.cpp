class Solution {
public:
    long long mod = 1e9+7;
    long long dp[1005][1005][2];

    int solve(int idx, bool start, int n, int k){
        if (k==0)
            return 1;
        if (idx==n)
            return 0;
        
        if (dp[idx][k][start] != -1)
            return dp[idx][k][start];
        
        long long cnt = 0;

        if (start){
            cnt = (cnt + solve(idx, false, n, k-1)) % mod;
            cnt = (cnt + solve(idx+1, true, n, k)) % mod;
        }
        else{
            cnt = (cnt + solve(idx+1, true, n, k)) % mod;
            cnt = (cnt + solve(idx+1, false, n, k)) % mod;
        }

        return dp[idx][k][start] = cnt;
    }

    int numberOfSets(int n, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(0, false, n, k);
    }
};