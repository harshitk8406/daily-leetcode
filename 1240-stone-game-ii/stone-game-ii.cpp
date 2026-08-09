class Solution {
public:
    int n;
    vector<int> suffix;
    vector<vector<int>> dp;
    
    int solve(int i, int m){
        if (i==n)
            return 0;
        if (dp[i][m]!=-1)
            return dp[i][m];
        int best = 0;
        for (int j=1; j<=2*m && i+j<=n; j++){
            int nextm = max(m,j);
            int curr = suffix[i] - solve(i+j, nextm);
            best = max(best, curr);
        }
        return dp[i][m] = best;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        suffix.assign(n+1, 0);
        for (int i=n-1; i>=0; i--){
            suffix[i] = suffix[i+1] + piles[i];
        }
        dp.assign(n, vector<int> (n+1, -1));
        return solve(0,1);
    }
};