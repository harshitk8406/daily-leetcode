class Solution {
public:
    struct Node {
        char leftchar = 0;
        char rightchar = 0;
        int len = 0;
        int pref = 0;
        int suff = 0;
        int best = 0;
    };

    vector<Node> tree;

    Node merge(Node left, Node right){
        Node res;

        res.leftchar = left.leftchar;
        res.rightchar = right.rightchar;
        res.len = left.len + right.len;

        res.best = max(left.best, right.best);

        res.pref = left.pref;
        if (left.pref == left.len && left.rightchar == right.leftchar)
            res.pref = left.len + right.pref;
        
        res.suff = right.suff;
        if (right.suff == right.len && left.rightchar == right.leftchar)
            res.suff = left.suff + right.len;
        
        if (left.rightchar == right.leftchar)
            res.best = max(res.best, left.suff + right.pref);
        
        return res;
    }

    void build(int node, int l, int r, const string &str){
        if (l==r){
            tree[node].leftchar = str[l];
            tree[node].rightchar = str[l];
            tree[node].len = 1;
            tree[node].pref = 1;
            tree[node].suff = 1;
            tree[node].best = 1;
            return;
        }

        int mid = l + (r-l)/2;

        build(node*2, l, mid, str);
        build(node*2+1, mid+1, r, str);

        tree[node] = merge(tree[node*2], tree[node*2+1]);
    }

    void update(int node, int l, int r, int idx, char ch){
        if(l==r){
            tree[node].leftchar = ch;
            tree[node].rightchar = ch;
            tree[node].len = 1;
            tree[node].pref = 1;
            tree[node].suff = 1;
            tree[node].best = 1;
            return;
        }

        int mid = l + (r-l)/2;

        if (idx <= mid)
            update(node*2, l, mid, idx, ch);
        else
            update(node*2+1, mid+1, r, idx, ch);
        
        tree[node] = merge(tree[node*2], tree[node*2+1]);
    }

    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size();
        int k = queryCharacters.size();

        tree.resize(4*n);

        build(1, 0, n-1, s);
        vector<int> ans;
        ans.reserve(k);

        for (int i=0; i<k; i++){
            update(1, 0, n-1, queryIndices[i], queryCharacters[i]);
            ans.push_back(tree[1].best);
        }
        return ans;
    }
};