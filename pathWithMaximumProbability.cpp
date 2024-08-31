class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, 
    vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int, vector<pair<double, int>>>adjlist;
        for (int i=0; i<edges.size(); i++){
            adjlist[edges[i][0]].push_back({succProb[i],edges[i][1]});
            adjlist[edges[i][1]].push_back({succProb[i],edges[i][0]});
        }
        priority_queue<pair<double, int>>pq;
        vector<double>vis(n, 0);
        pq.push({1, start_node});
        while(!pq.empty()){
            int node=pq.top().second;
            double prob=pq.top().first;
            pq.pop();
            if(vis[node]>=prob) continue;
            vis[node]=prob;
            cout<<prob<<" "<<node<<endl;
            for (auto x: adjlist[node]){
                if(vis[x.second]>=prob*x.first) continue;
                pq.push({prob*x.first, x.second});
            }
        }
        return vis[end_node];
    }
};
