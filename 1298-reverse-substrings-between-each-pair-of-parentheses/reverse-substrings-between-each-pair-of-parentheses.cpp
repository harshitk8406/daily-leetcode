class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        vector<int> arr(n);
        stack<int> st;

        for (int i=0; i<n; i++){
            if (s[i]=='(')
                st.push(i);
            else if (s[i]==')'){
                int top = st.top();
                st.pop();

                arr[top] = i;
                arr[i] = top;
            }
        }

        string str;
        int cnt = 1;
        for (int i=0; i>=0 && i<n; i+=cnt){
            if (islower(s[i]))
                str += s[i];
            else{
                i = arr[i];
                cnt = -cnt;
            }
        }
        return str;
    }
};