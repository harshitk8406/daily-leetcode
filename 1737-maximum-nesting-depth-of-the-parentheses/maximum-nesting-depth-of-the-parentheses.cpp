class Solution {
public:
    int maxDepth(string s) {
        int mx = 0;
        int len = 0;

        for (char ch : s){
            if (ch==')'){
                len--;
                continue;
            }
            if (ch!='(')
                continue;
            len++;
            mx = max(mx, len);
        }
        return mx;
    }
};