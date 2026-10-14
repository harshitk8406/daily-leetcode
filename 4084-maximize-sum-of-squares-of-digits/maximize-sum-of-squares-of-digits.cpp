class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9*num)
            return "";
        int ans = sum/9;
        int res = sum%9;

        string str;
        str = string(ans, '9') + char('0'+res) + string(num, '0');
        return str.substr(0, num);
    }
};