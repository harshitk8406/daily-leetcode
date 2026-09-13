class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int,int>> arr, ans;
        int mx = 0;

        for (int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if (img1[i][j]==1)
                    arr.emplace_back(i,j);
                if (img2[i][j]==1)
                    ans.emplace_back(i,j);
            }
        }

        vector<vector<int>> cnt(2*n, vector<int> (2*n, 0));
        for (auto &x : arr){
            for (auto &y : ans){
                int dx = y.first - x.first + n;
                int dy = y.second - x.second + n;
                mx = max(mx, ++cnt[dx][dy]);
            }
        }
        return mx;
    }
};