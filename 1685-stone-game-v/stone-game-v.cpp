class Solution {
public:
    vector<vector<int>> dp;
    vector<int> prefix;
    vector<int> arr;

    int solve(int l, int r){
        if (l>=r)
            return 0;
        
        if (dp[l][r]!=-1)
            return dp[l][r];
        
        int ans = 0;
        int left = 0;
        int right = prefix[r+1] - prefix[l];

        for (int i=l; i<r; i++){
            left += arr[i];
            right -= arr[i];

            if (left < right){
                if (ans >= 2*left)
                    continue;
                ans = max(ans, left + solve(l,i));
            }
            else if (left > right){
                if (ans >= 2*right)
                    break;
                ans = max(ans, right + solve(i+1, r));
            }
            else{
                ans = max({ans, left + solve(l,i), right + solve(i+1,r)});
            }
        }
        return dp[l][r] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) {
        arr = stoneValue;
        int n = arr.size();
        prefix.resize(n+1);

        for (int i=0; i<n; i++){
            prefix[i+1] = prefix[i] + arr[i];
        }

        dp.assign(n, vector<int> (n, -1));
        return solve(0, n-1);
    }
};