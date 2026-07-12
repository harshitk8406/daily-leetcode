class Solution {
public:
    int mirrorDistance(int n) {
        int m = n;
        int ans = 0;
        while(m>0){
            ans = ans*10 + (m%10);
            m/=10;
        }
        return abs(n-ans);
    }
};