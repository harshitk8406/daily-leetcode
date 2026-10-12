class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int arr[30] = {0};
        long long ans = 0;
        long long mod = 1e9+7;

        for (int x : nums){
            for (int i=0; i<30; i++){
                if (x & (1 << i))
                    arr[i]++;
            }
        }

        while(k--){
            long long x = 0;
            for (int i=0; i<30; i++){
                if (arr[i]){
                    x |= 1LL << i;
                    arr[i]--;
                }
            }
            ans = (ans + x*x) % mod;
        }
        return (int)ans;
    }
};