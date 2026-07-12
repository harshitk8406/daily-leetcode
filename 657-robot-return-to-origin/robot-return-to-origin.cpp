class Solution {
public:
    bool judgeCircle(string moves) {
        int n = moves.size();
        int up=0, down=0;
        int left=0, right=0;
        for (char ch : moves){
            if (ch=='U')
                up++;
            else if (ch=='D')
                down++;
            else if (ch=='L')
                left++;
            else if (ch=='R')
                right++;
        }
        if (up==down && left==right)
            return true;
        return false;
    }
};