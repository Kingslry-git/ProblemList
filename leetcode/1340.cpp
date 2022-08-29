class Solution {
public:
    int minJumps(vector<int>& w) {
        const int INF = 1e6;
        int n = w.size();
        unordered_map<int, vector<int>> hash;
        for(int i = 0 ; i < w.size(); i ++)
        hash[w[i]].push_back(i);

        vector<int> dist(n, INF);
        dist[0] = 0;
        queue<int> q;
        q.push(0);

        //t表示下标
        while(q.size())
        {
            auto t = q.front(); q.pop();
            for(int i = t - 1; i <= t + 1; i += 2)
            {
                if(i >= 0 && i < n && dist[i] > dist[t] + 1)
                {
                    dist[i] = dist[t] + 1;
                    q.push(i);
                }
            }

            int v = w[t];
            if(hash.count(v))
            {
                for(int k : hash[v])
                    if(dist[k] > dist[t] + 1) 
                    {
                        dist[k] = dist[t] + 1;
                        q.push(k);
                    }
                hash.erase(v);
            }
        }
        return dist[n - 1];
    }
};