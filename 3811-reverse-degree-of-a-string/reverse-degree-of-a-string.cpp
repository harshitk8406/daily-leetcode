class Solution {
public:
    int reverseDegree(string s) {
        unordered_map<char,int> mp;
        int temp = 26;
        for (char ch='a'; ch<='z'; ch++){
            mp[ch] = temp;
            temp--;
        }
        int sum = 0;
        for (int i=0; i<s.size(); i++){
            char ch = s[i];
            sum += (mp[ch] * (i+1));
        }
        return sum;
    }
};