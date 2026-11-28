class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int cheap = INT_MAX;
        vector<int> have(n+1);
        for (auto &it : items){
            have[it[0]]++;
            cheap = min(cheap, it[1]);
        }
        vector<int> deals(n+1, -1);

        vector<pair<int,int>> worth;
        for (auto &it : items){
            if (it[1] < 2*cheap)
                worth.emplace_back(it[1], it[0]);
        }

        priority_queue heap(greater<>(), std::move(worth));
        int copy = 0;
        while(!heap.empty() && heap.top().first <= budget){
            auto [price, factor] = heap.top();
            heap.pop();
            if (deals[factor] < 0){
                for (int i=factor; i<=n; i+=factor){
                    deals[factor] += have[i];
                }
            }

            int pairs = min(deals[factor], budget/price);
            copy += 2*pairs;
            budget -= pairs*price;
        }
        return copy + budget/cheap;
    }
};