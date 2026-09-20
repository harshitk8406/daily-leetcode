class Solution {
public:
    int reverseDegree(string s) {
        int start = 26;
        unordered_map<char,int> mp;
        for (char ch='a'; ch<='z'; ch++){
            mp[ch] = start;
            start--;
        }

        int sum = 0;
        for (int i=0; i<s.size(); i++){
            char ch = s[i];
            sum += (mp[ch] * (i+1));
        }
        return sum;
    }
};