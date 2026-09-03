class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn = nums1[0];
        bool flag = 0;

        for (int x : nums1){
            mn = min(mn, x);
            flag |= x & 1;
        }

        return (mn & 1) == flag;
    }
};