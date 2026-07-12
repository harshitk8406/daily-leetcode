class Solution {
public:
    bool search(char ch, string word){
        for (char c : word){
            if (c==ch)
                return true;
        }
        return false;
    }

    int numberOfSpecialChars(string word) {
        int cnt = 0;
        vector<bool> vis(26, false);
        for (char ch : word){
            if (ch >= 'a' && ch <= 'z'){
                if (search(ch-32, word) && !vis[ch-'a']){
                    cnt++;
                    vis[ch-'a'] = true;
                }
            }
        }
        return cnt;
    }
};