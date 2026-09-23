class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum - x;

        if (target < 0)
            return -1;
        if (target == 0)
            return n;
        
        int l=0, r=0;
        int tot = 0;
        int mx = -1;

        while(r < n){
            tot += nums[r];
            while(l<=r && tot > target){
                tot -= nums[l];
                l++;
            }

            if (tot == target)
                mx = max(mx, r-l+1);
            
            r++;
        }
        if (mx==-1)
            return -1;
        return n-mx;
    }
};