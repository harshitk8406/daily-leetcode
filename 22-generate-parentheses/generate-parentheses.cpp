class Solution {
public:
    vector<string> ans;
    string str;

    void dfs(int start, int end){
        if (start==0 && end==0){
            ans.push_back(str);
            return;
        }
        if (start > 0){
            str.push_back('(');
            dfs(start-1, end);
            str.pop_back();
        }
        if (end > start){
            str.push_back(')');
            dfs(start, end-1);
            str.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        dfs(n,n);
        return ans;
    }
};