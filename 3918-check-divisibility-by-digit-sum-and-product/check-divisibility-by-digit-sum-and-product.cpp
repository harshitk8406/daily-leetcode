class Solution {
public:
    vector<int> getSum(int n){
        int sum = 0;
        int prod = 1;
        while(n!=0){
            sum += (n%10);
            prod *= (n%10);
            n/=10;
        }
        return {sum, prod};
    }

    bool checkDivisibility(int n) {
        vector<int> ans = getSum(n);
        int sum = ans[0] + ans[1];
        return !(n%sum);
    }
};