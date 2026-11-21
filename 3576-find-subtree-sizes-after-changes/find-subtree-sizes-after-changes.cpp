class Solution {
public:
    vector<int> arr;

    void dfs(int ind, vector<vector<int>> &adj, string &str, vector<int> &prev, vector<int> &last){
        int x = str[ind] - 'a';
        int old = last[x];

        if (ind && old!=-1)
            prev[ind] = old;
        last[x] = ind;

        for (int v : adj[ind]){
            dfs(v, adj, str, prev, last);
        }
        last[x] = old;
    }

    int solve(int ind, vector<vector<int>> &tree){
        arr[ind] = 1;
        for (int v : tree[ind]){
            arr[ind] += solve(v, tree);
        }
        return arr[ind];
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n), tree(n);

        for (int i=1; i<n; i++){
            adj[parent[i]].push_back(i);
        }

        vector<int> last(26, -1);
        dfs(0, adj, s, parent, last);

        for (int i=1; i<n; i++){
            tree[parent[i]].push_back(i);
        }

        arr.resize(n);
        solve(0, tree);
        return arr;
    }
};