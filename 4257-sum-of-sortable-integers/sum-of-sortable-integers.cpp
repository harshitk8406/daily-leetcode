class Solution {
public:
    bool solve(vector<int> &nums, int k){
        int n = nums.size();
        int prev = 0;

        for (int i=0; i<n; i+=k){
            int cnt = 0;
            int mn = nums[i];
            int mx = nums[i];

            for (int j=i; j<i+k-1; j++){
                if (nums[j] > nums[j+1])
                    cnt++;
                
                mn = min(mn, nums[j+1]);
                mx = max(mx, nums[j+1]);
            }

            if (nums[i+k-1] > nums[i])
                cnt++;
            
            if (cnt > 1 || prev > mn)
                return false;
            
            prev = mx;
        }
        return true;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i=1; i*i<=n; i++){
            if (n%i==0){
                if (solve(nums, i))
                    ans += i;
                
                if (i*i != n && solve(nums, n/i))
                    ans += n/i;
            }
        }
        return ans;
    }
};