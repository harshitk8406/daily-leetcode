class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        unordered_map<int,int> mp;
        for (int x : nums)
            mp[x]++;
        
        if (n > mx+1 || n < mx)
            return false;
        for (auto it : mp){
            if (it.first==mx && it.second!=2)
                return false;
            if (it.first!=mx && it.second==2)
                return false;
        }
        return true;
    }
};