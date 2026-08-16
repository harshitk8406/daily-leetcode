class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt1=0, cnt2=0, cnt3=0;
        for (int x : stones){
            if (x%3==0)
                cnt1++;
            else if (x%3==1)
                cnt2++;
            else
                cnt3++;
        }

        if (cnt1%2==0){
            if (cnt2 > 0 && cnt3 > 0)
                return true;
            return false;
        }
        else{
            if (abs(cnt2 - cnt3) > 2)
                return true;
            return false;
        }
        return true;
    }
};