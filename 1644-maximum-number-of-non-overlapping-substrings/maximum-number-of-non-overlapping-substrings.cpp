class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int count[26] = {};
        int first[26], last[26];

        fill(first, first+26, -1);
        fill(last, last+26, -1);

        vector<int> order;

        for (int i=0; i<s.size(); i++){
            int c = s[i]-'a';
            if (count[c]==0){
                first[c] = i;
                order.push_back(c);
            }

            count[c]++;
            last[c] = i;
        }

        vector<string> strs;
        deque<array<int, 3>> q;

        for (int c : order){
            q.push_front({first[c], last[c], count[c]});

            int l = INT_MAX;
            int r = INT_MIN;
            int total = 0;

            for (auto &it : q){
                total += it[2];
                l = min(l, it[0]);
                r = max(r, it[1]);

                if (total == r - l + 1)
                    break;
            }

            if (total == r - l + 1){
                strs.push_back(s.substr(l, r-l+1));
                q.clear();
            }
        }
        return strs;
    }
};