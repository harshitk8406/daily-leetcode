class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for (int x : nums)
            mp[x]++;
        for (auto it : mp){
            if (it.first==0){
                if (it.second==n)
                    return 0;
            }
        }

        int xori = 0;
        for (int x : nums){
            xori = xori ^ x;
        }

        if (xori==0)
            return n-1;
        return n;
    }
};