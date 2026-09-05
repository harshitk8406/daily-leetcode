class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int pref = -1;
        int temp = 0;
        int mx = 0;
        int n = nums.size();

        for (int i=0; i<n; i++){
            pref = max(pref, nums[i]);

            if (i==temp)
                mx = pref;
            if (nums[i] < mx-k)
                temp = i+1;
        }

        if (temp < n)
            return temp;
        return -1;
    }
};