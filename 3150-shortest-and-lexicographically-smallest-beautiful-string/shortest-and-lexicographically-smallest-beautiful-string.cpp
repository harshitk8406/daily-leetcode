class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string str;
        int n = s.size();

        for (int i=0; i<n; i++){
            int ones = 0;
            string curr;
            for (int j=i; j<n; j++){
                curr += s[j];
                if (s[j]=='1')
                    ones++;
                
                if (ones > k)
                    break;
                if (ones==k){
                    if (str.empty() || curr.size() < str.size() || (curr.size()==str.size() && curr < str))
                        str = curr;
                }
            }
        }
        return str;
    }
};