class Solution {
public:
    int sumDig(int n){
        int sum = 0;
        while(n){
            sum += (n%10);
            n/=10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<array<int,3>> arr(n);

        for (int i=0; i<n; i++){
            int sum = sumDig(nums[i]);
            arr[i] = {sum, nums[i], i};
        }

        sort(arr.begin(), arr.end());

        vector<bool> vis(n, false);
        int cnt = 0;
        for (int i=0; i<n; i++){
            if (vis[i] || arr[i][2]==i)
                continue;
            int j=i, len=0;
            while(!vis[j]){
                vis[j] = true;
                j = arr[j][2];
                len++;
            }
            cnt += len-1;
        }
        return cnt;
    }
};