class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for (int x : nums){
            mp[x]++;
        }
        if (mp.find(k)==mp.end())
            return k;
        
        for (int i=k; ; i+=k){
            if (mp.find(i)!=mp.end())
                continue;
            return i;
        }
        return -1;
    }
};