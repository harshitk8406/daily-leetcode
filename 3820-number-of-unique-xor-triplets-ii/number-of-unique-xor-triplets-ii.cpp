class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int mx = 2048;
        vector<bool> pairxor(mx, false);
        vector<bool> tripletxor(mx, false);
        int n = nums.size();
        for (int i=0; i<n; i++){
            for (int j=i; j<n; j++){
                pairxor[nums[i]^nums[j]] = true;
            }
        }

        for (int i=0; i<mx; i++){
            if (!pairxor[i])
                continue;
            for (int x : nums){
                tripletxor[i^x] = true;
            }
        }

        int cnt = 0;
        for (int i=0; i<mx; i++){
            if (tripletxor[i])
                cnt++;
        }
        return cnt;
    }
};