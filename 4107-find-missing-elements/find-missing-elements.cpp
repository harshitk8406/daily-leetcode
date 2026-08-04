class Solution {
public:
    bool search(vector<int> &nums, int k){
        for (int x : nums){
            if (x==k)
                return true;
        }
        return false;
    }
    
    vector<int> findMissingElements(vector<int>& nums) {
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());
        vector<int> arr;
        for (int i=low; i<=high; i++){
            if (!search(nums,i))
                arr.push_back(i);
        }
        sort(arr.begin(), arr.end());
        return arr;
    }
};