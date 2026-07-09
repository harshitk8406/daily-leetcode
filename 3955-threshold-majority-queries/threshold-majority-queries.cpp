class Solution {
public:
    vector<int> subarrayMajority(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int qn = queries.size();

        struct Query {
            int l,r,thr,idx;
        };

        vector<Query> arr(qn);
        vector<int> res(qn);
        for (int i=0; i<qn; i++){
            arr[i].l = queries[i][0];
            arr[i].r = queries[i][1];
            arr[i].thr = queries[i][2];
            arr[i].idx = i;
        }

        unordered_map<int,int> mp(n);
        vector<set<int>> freq(n+1);
        int maxF = 0;

        int bsize = max<int>(1, n/sqrt(qn));
        sort(arr.begin(), arr.end(), [&](auto &a, auto &b) -> bool {
            return make_pair(a.l/bsize, (a.l/bsize & 1) ? -a.r : a.r)
                < make_pair(b.l/bsize, (a.l/bsize & 1) ? -b.r : b.r);
        });

        auto add = [&](int idx) -> void {
            int num = nums[idx];
            freq[mp[num]].erase(num);
            freq[++mp[num]].insert(num);
            if (mp[num] > maxF)
                maxF = mp[num];
        };

        auto remove = [&](int idx) -> void {
            int num = nums[idx];
            freq[mp[num]].erase(num);
            if (int resF = --mp[num]; resF > 0)
                freq[resF].insert(num);
            
            if (maxF > 0 && freq[maxF].empty())
                maxF--;
        };

        auto get_answer = [&](const Query &query) -> int {
            if (maxF < query.thr)
                return -1;
            return *freq[maxF].begin();
        };

        int curl = 0;
        int curr = -1;

        for (Query &q : arr){
            while(curr < q.r){
                curr++;
                add(curr);
            }

            while(curl > q.l){
                curl--;
                add(curl);
            }

            while(curr > q.r){
                remove(curr);
                curr--;
            }

            while(curl < q.l){
                remove(curl);
                curl++;
            }
            res[q.idx] = get_answer(q);
        }
        return res;
    }
};