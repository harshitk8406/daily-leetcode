class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());
        vector<vector<int>> arrs;
        unordered_map<int,int> mp;
        int idx = -1;

        for (int i=0; i<arr.size(); i++){
            if (i==0 || arr[i]-arr[i-1] > limit){
                arrs.push_back({});
                idx++;
            }
            arrs[idx].push_back(arr[i]);
            mp[arr[i]] = idx;
        }

        vector<int> res(arrs.size(), 0);
        for (int i=0; i<nums.size(); i++){
            int curr = mp[nums[i]];
            nums[i] = arrs[curr][res[curr]];
            res[curr]++;
        }
        return nums;
    }
};