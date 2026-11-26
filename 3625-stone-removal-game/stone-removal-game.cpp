class Solution {
public:
    bool canAliceWin(int n) {
        if (n<10)
            return false;
        
        int rem = 10;
        bool flag = true;

        while(n >= rem){
            n-=rem;
            rem--;
            flag = !flag;
        }
        return !flag;
    }
};