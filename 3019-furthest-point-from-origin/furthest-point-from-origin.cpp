class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left=0;
        int right=0;
        int space=0;

        for (char ch : moves){
            if (ch=='L')
                left++;
            else if (ch=='R')
                right++;
            else
                space++;
        }

        if (left==right)
            return space;

        int a = abs(left-right);
        return a + space;
    }
};