class Solution {
public:
    int numberOfSteps(int num) {
        int cnt = 0;
        while(num!=0){
            if (num%2==0)
                num/=2;
            else if (num%2!=0)
                num--;
            cnt++;
        }
        return cnt;
    }
};