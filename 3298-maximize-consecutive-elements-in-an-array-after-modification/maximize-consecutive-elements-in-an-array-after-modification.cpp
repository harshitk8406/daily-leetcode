class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        ranges::sort(nums);
        unordered_map<int,int> mp;
        int mx = 0;

        for (int x : nums){
            mp[x+1] = mp[x] + 1;
            mp[x] = mp[x-1] + 1;
            mx = max({mx, mp[x], mp[x+1]});
        }
        return mx;
    }
};