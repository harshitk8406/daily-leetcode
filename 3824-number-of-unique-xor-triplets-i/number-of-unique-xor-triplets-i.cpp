class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n<=2)
            return n;
        
        int ans = 0;
        for (int x : nums){
            ans |= x;
        }
        return ans+1;
    }
};