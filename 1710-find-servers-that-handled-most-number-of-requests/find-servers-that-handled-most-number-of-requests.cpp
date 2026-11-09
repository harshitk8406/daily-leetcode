class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> arr;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        set<int> servers;

        for (int i=0; i<k; i++){
            servers.insert(i);
        }
        vector<int> ans(k, 0);

        int n = arrival.size();
        int mx = 0;
        for (int i=0; i<n; i++){
            while(!pq.empty() && arrival[i] >= pq.top().first){
                servers.insert(pq.top().second);
                pq.pop();
            }

            if (servers.size() == 0)
                continue;
            
            int req = i%k;
            auto it = servers.lower_bound(req);
            auto avail = -1;

            if (it == servers.end())
                avail = *servers.begin();
            else
                avail = *it;
            
            servers.erase(avail);

            pq.push({arrival[i] + load[i], avail});
            ans[avail]++;

            mx = max(mx, ans[avail]);
        }

        for (int i=0; i<k; i++){
            if (ans[i]==mx)
                arr.push_back(i);
        }
        return arr;
    }
};