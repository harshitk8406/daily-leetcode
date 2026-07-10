class Solution {
public:
    int maximum69Number (int num) {
        vector<int> arr;
        while(num>0){
            arr.push_back(num%10);
            num/=10;
        }
        reverse(arr.begin(), arr.end());
        int n = arr.size();
        for (int i=0; i<n; i++){
            if (arr[i]==9)
                continue;
            else if (arr[i]==6){
                arr[i] = 9;
                break;
            }
        }
        int ans = 0;
        for (int x : arr) {
            ans = ans * 10 + x;
        }
        return ans;
    }
};