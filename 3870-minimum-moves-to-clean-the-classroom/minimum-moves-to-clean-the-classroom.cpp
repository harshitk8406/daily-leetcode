class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        int k = 0;
        int sr = 0, sc = 0;

        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (classroom[i][j]=='S'){
                    sr = i;
                    sc = j;
                }
                else if (classroom[i][j]=='L')
                    dp[i][j] = k++;
            }
        }

        if (k==0)
            return 0;
        
        int total = (1 << k) - 1;
        vector<vector<vector<int>>> best(m, vector<vector<int>> (n, vector<int> (1 << k, -1)));

        struct State{
            int r, c, mask, e, moves;
        };

        queue<State> q;
        best[sr][sc][0] = energy;
        q.push({sr, sc, 0, energy, 0});

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        while(!q.empty()){
            State curr = q.front();
            q.pop();

            for (int i=0; i<4; i++){
                int nr = curr.r + dr[i];
                int nc = curr.c + dc[i];

                if (nr<0 || nr>=m || nc<0 || nc>=n)
                    continue;
                
                if (classroom[nr][nc]=='X')
                    continue;
                
                int ne = curr.e - 1;
                if (ne < 0)
                    continue;
                
                int nm = curr.mask;

                if (classroom[nr][nc]=='R')
                    ne = energy;
                if (classroom[nr][nc]=='L')
                    nm |= (1 << dp[nr][nc]);

                if (nm == total)
                    return curr.moves + 1;

                if (ne <= best[nr][nc][nm])
                    continue;
                
                best[nr][nc][nm] = ne;
                q.push({nr, nc, nm, ne, curr.moves + 1});
            }
        }
        return -1;
    }
};