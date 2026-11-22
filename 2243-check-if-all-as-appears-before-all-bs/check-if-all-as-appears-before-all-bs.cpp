class Solution {
public:
    bool checkString(string s) {
        bool flag = false;
        for (char ch : s){
            if (ch=='b')
                flag = true;
            
            if (flag && ch=='a')
                return false;
        }
        return true;
    }
};