class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int arr[1501] = {};
        for (auto &it : items){
            int fact = it[0];
            for (int i=1; i<=1500; i++){
                if (fact%i==0)
                    arr[i]++;
            }
        }

        vector<int> dp(budget+1, 0);
        for (auto &it : items){
            int fact = it[0];
            int price = it[1];
            vector<int> ndp = dp;

            for (int i=budget; i>=price; i--){
                ndp[i] = max(ndp[i], dp[i-price] + arr[fact]);
            }
            for (int i=price; i<=budget; i++){
                ndp[i] = max(ndp[i], ndp[i-price] + 1);
            }
            dp = move(ndp);
        }
        return *max_element(dp.begin(), dp.end());
    }
};