class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int mp[26] = {};
        for (char ch : s){
            mp[ch-'a']++;
        }
        for (char ch : target){
            mp[ch-'a']--;
        }

        for (int i=target.size()-1; i>=0; i--){
            int curr = target[i] - 'a';
            mp[curr]++;

            bool flag = true;
            for (int j=0; j<26; j++){
                if (mp[j] < 0){
                    flag = false;
                    break;
                }
            }
            if (!flag)
                continue;
            
            int next = -1;
            for (int j=curr+1; j<26; j++){
                if (mp[j] > 0){
                    next = j;
                    break;
                }
            }

            if (next==-1)
                continue;
            mp[next]--;
            string str = target.substr(0,i);
            str += char('a' + next);

            for (int j=0; j<26; j++){
                str.append(mp[j], char('a'+j));
            }
            return str;
        }
        return "";
    }
};