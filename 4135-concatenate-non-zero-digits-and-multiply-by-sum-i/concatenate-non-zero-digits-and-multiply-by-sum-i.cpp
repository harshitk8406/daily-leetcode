class Solution {
public:
    vector<int> solve(int n){
        vector<int> arr;
        while(n>0){
            int a = n%10;
            if (a!=0)
                arr.push_back(a);
            n/=10;
        }
        return arr;
    }

    long long sumAndMultiply(int n) {
        vector<int> arr = solve(n);
        long long sum = accumulate(arr.begin(), arr.end(), 0);
        int m = arr.size();
        long long x = 0;
        for (int i=m-1; i>=0; i--){
            x += arr[i]*pow(10,i);
        }
        return x * sum;
    }
};