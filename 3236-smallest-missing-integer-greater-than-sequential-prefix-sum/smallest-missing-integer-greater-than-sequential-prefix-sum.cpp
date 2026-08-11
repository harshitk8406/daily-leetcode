class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];

        for (int i=1; i<n; i++){
            if (nums[i]==nums[i-1]+1)
                sum += nums[i];
            else
                break;
        }

        while(true){
            bool flag = false;
            for (int x : nums){
                if (x==sum){
                    flag = true;
                    break;
                }
            }
            if (!flag)
                return sum;
            sum++;
        }
        return 0;
    }
};