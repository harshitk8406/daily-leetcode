class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> arr(k,0), dp(k,0);

        for (int x : nums){
            int a = x%k;
            vector<long long> next(k,0);
            next[a]++;

            for (int r=0; r<k; r++){
                int newr = (r*a)%k;
                next[newr] += dp[r];
            }

            for (int r=0; r<k; r++){
                arr[r] += next[r];
            }
            dp = next;
        }
        return arr;
    }
};