class Solution {
public:
    bool search(vector<int> &arr, int k){
        if (arr.empty())
            return false;
        for (int i=0; i<arr.size(); i++){
            if (arr[i]==k)
                return true;
        }
        return false;
    }

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int k = min(m,n);
        vector<int> ans;

        if (k==n){
            for (int i=0; i<k; i++){
                if (search(nums1, nums2[i]) && !search(ans, nums2[i]))
                    ans.push_back(nums2[i]);
            }
        }
        else if (k==m){
            for (int i=0; i<k; i++){
                if (search(nums2, nums1[i]) && !search(ans, nums1[i]))
                    ans.push_back(nums1[i]);
            }
        }
        return ans;
    }
};