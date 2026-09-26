class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for (auto &k : knowledge){
            mp[k[0]] = k[1];
        }

        string str;
        for (int i=0; i<s.size(); i++){
            if (s[i]=='('){
                int j = s.find(")", i+1);
                auto t = s.substr(i+1, j-i-1);
                str += mp.count(t) ? mp[t] : "?";
                i = j;
            }
            else
                str += s[i];
        }
        return str;
    }
};