class Solution {
public:
    string removeOuterParentheses(string s) {
        string str;
        int cnt = 0;

        for (char ch : s){
            if (ch=='('){
                if (cnt > 0)
                    str.push_back(ch);
                cnt++;
            }
            else if (ch==')'){
                cnt--;
                if (cnt > 0)
                    str.push_back(ch);
            }
        }
        return str;
    }
};