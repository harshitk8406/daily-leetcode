class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> res(n);
        for (int i=0; i<n; i++){
            res[i] = {nums[i], i};
        }
        sort(res.begin(), res.end());

        vector<int> getI(n);
        for (int i=0; i<n; i++){
            getI[res[i].second] = i;
        }

        vector<vector<int>> st(n, vector<int> (18));

        int r=0;
        for (int i=0; i<n; i++){
            if (r<i)
                r = i;
            while(r+1 < n && res[r+1].first - res[r].first <= maxDiff && res[r+1].first - res[i].first <= maxDiff)
                r++;
            st[i][0] = r;
        }

        for (int j=1; j<18; j++){
            for (int i=0; i<n; i++){
                st[i][j] = st[st[i][j-1]][j-1];
            }
        }

        vector<int> ans(queries.size(), -1);
        for (int i=0; i<queries.size(); i++){
            int a = getI[queries[i][0]];
            int b = getI[queries[i][1]];

            if (a>b)
                swap(a,b);
            if (a==b){
                ans[i] = 0;
                continue;
            }

            int curr = a;
            int steps = 0;
            for (int j=17; j>=0; j--){
                if (st[curr][j] < b){
                    curr = st[curr][j];
                    steps += (1 << j);
                }
            }
            if (st[curr][0] >= b)
                ans[i] = steps+1;
            else
                ans[i] = -1;
        }
        return ans;
    }
};