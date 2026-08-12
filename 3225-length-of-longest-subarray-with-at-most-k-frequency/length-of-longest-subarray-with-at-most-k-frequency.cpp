class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int len = 1;
        int l=0;
        int r=0;
        unordered_map<int,int> mp;

        while(r<n){
            int x = nums[r];
            mp[x]++;
            while(mp[x] > k){
                int y = nums[l];
                mp[y]--;
                l++;
            }
            len = max(len, r-l+1);
            r++;
        }
        return len;
    }
};