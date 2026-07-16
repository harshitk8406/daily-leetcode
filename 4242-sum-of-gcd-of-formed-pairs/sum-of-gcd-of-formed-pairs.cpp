class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefG(n,0);

        int mx = nums[0];
        for (int i=0; i<n; i++){
            mx = max(mx, nums[i]);
            prefG[i] = gcd(nums[i],mx);
        }

        sort(prefG.begin(), prefG.end());
        long long sum = 0;
        int left=0;
        int right = n-1;
        while(left < right){
            int x = gcd(prefG[left], prefG[right]);
            sum += x;
            left++;
            right--;
        }
        return sum;
    }
};