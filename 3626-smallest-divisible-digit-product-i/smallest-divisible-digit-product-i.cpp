class Solution {
public:
    int solve(int n){
        int prod = 1;
        while(n!=0){
            prod *= (n%10);
            n/=10;
        }
        return prod;
    }

    int smallestNumber(int n, int t) {
        for (int i=n; ; i++){
            if (solve(i) % t == 0)
                return i;
        }
        return -1;
    }
};