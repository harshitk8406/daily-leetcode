class Solution {
public:
    long long countCommas(long long n) {
        if (n<=3)
            return 0;
        long long cnt = 0;
        for (long long i=1000; i<=n; i*=1000){
            cnt += n-i+1;
        }
        return cnt;
    }
};