class Solution {
public:
    int sumCounts(vector<int>& nums) {
        long long mod = 1e9+7;
        int n = nums.size();
        vector<long long> arr(n+1), tot(n+1);
        unordered_map<int,int> mp;
        long long sum = 0;
        int r=0;

        while(r < n){
            int x = mp.count(nums[r]) ? mp[nums[r]] : -1;
            long long a = 0, b = 0;

            for (int i=n-x-1; i>0; i-=i & -i){
                a += arr[i];
                b += tot[i];
            }

            long long ans = (long long) (r-x)*(r-x) - 2*(b-x*a);
            sum = (sum + (n-r)*ans) % mod;

            for (int i=n-x; i<=n; i+=i&-i){
                arr[i]++;
                tot[i] += x;
            }

            mp[nums[r]] = r;
            r++;
        }
        return sum;
    }
};