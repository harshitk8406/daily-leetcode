class Solution {
public:
    int countAsterisks(string s) {
        bool n = false;
        int stars = 0;
        for (auto x : s){
            if (x=='*' && !n)
                stars++;
            else if (x=='|')
                n = !n;
        }
        return stars;
    }
};