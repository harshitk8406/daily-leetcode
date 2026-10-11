class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (int i=0; i<n; i++){
            int idx = i+1;
            if (n%idx==0)
                sum += (nums[i]*nums[i]);
        }
        return sum;
    }
};