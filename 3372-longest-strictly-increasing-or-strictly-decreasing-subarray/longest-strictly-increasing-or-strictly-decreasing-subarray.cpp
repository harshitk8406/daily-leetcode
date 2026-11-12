class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int best = 1;
        int inc = 1;
        int dec = 1;

        for (int i=1; i<nums.size(); i++){
            if (nums[i-1] < nums[i])
                inc++;
            else
                inc = 1;
            
            if (nums[i-1] > nums[i])
                dec++;
            else
                dec = 1;
            
            best = max({best, inc, dec});
        }
        return best;
    }
};