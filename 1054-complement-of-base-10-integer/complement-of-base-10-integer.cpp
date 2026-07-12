class Solution {
public:
    int bitwiseComplement(int n) {
        if (n==0 || n==1)
            return !n;
        vector<int> arr;
        while(n>0){
            arr.push_back(n%2);
            n/=2;
        }
        reverse(arr.begin(), arr.end());
        for (int &x : arr){
            if (x==0)
                x = 1;
            else if (x==1)
                x = 0;
        }
        int ans = 0;
        int base = 1;
        for (int i=arr.size()-1; i>=0; i--){
            if (arr[i]==1)
                ans += base;
            base = base*2;
        }
        return ans;
    }
};