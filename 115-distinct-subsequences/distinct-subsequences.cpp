class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();

        if (m < n)
            return 0;
        
        vector<vector<unsigned long long>> dp(m+1, vector<unsigned long long> (n+1));
        for (int i=0; i<=m; i++){
            dp[i][n] = 1;
        }

        for (int i=m-1; i>=0; i--){
            char ch = s.at(i);
            for (int j=n-1; j>=0; j--){
                char tch = t.at(j);
                if (ch == tch)
                    dp[i][j] = dp[i+1][j+1] + dp[i+1][j];
                else
                    dp[i][j] = dp[i+1][j];
            }
        }
        return dp[0][0];
    }
};