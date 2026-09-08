class Solution {
public:
    int countCommas(int n) {
        int cnt = 0;
        int temp = n;
        while(temp!=0){
            cnt++;
            temp/=10;
        }

        if (cnt < 4)
            return 0;
        
        cnt = 0;
        for (int i=1000; i<=n; i++){
            if (i<=1e5)
                cnt++;
        }
        return cnt;
    }
};