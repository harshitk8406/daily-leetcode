class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n==1 || n==2)
            return n;
        int mxi = 0;
        int mni = 0;

        for (int i=0; i<n; i++){
            if (nums[i] > nums[mxi]){
                mxi = i;
            }
            if (nums[i] < nums[mni]){
                mni = i;
            }
        }

        return min({max(mxi, mni)+1, n-min(mxi, mni), min(mxi, mni)+1 + n-max(mxi, mni)});
    }
};