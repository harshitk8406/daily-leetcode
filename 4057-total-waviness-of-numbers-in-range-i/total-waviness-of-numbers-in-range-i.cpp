class Solution {
public:
    int help(int n){
        vector<int> arr;
        int ans = 0;
        while(n>0){
            arr.push_back(n%10);
            n/=10;
        }
        reverse(arr.begin(), arr.end());
        for (int i=1; i<arr.size()-1; i++){
            if (arr[i] > arr[i-1] && arr[i] > arr[i+1])
                ans++;
            else if (arr[i] < arr[i-1] && arr[i] < arr[i+1])
                ans++;
        }
        return ans;
    }

    int totalWaviness(int num1, int num2) {
        int cnt = 0;
        for (int i=num1; i<=num2; i++){
            if (i < 100)
                continue;
            cnt += help(i);
        }
        return cnt;
    }
};