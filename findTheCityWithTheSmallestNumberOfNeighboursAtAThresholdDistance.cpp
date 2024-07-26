class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int d) {
        unordered_map<int, vector<pair<int,int> > >adjlist;
        for (int i=0; i<edges.size(); i++){
            for (int j=0; j<3; j++){
                adjlist[edges[i][0]].push_back({edges[i][1], edges[i][2]});
                adjlist[edges[i][1]].push_back({edges[i][0], edges[i][2]});
            }
        }
        int minans=101, ansind=0;
        for (int i=0; i<n; i++){
            int ans=0;
            priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > >q;
            q.push({0,i});
            vector<int>vis(n,10000);
            vis[i]=0;
            // vector
            while(q.empty()!=true){
                int dist=q.top().first;
                int index=q.top().second;
                q.pop();
                // cout<<dist<<" "<<index<<endl;
                for (auto x: adjlist[index]){
                    if( dist+x.second<=d && vis[x.first]>dist+x.second){
                        q.push({dist+x.second, x.first});
                        if(vis[x.first]==10000) ans++;
                        vis[x.first]=dist+x.second;
                    } 
                }
            }
            // cout<<ans<<endl;
            if(ans<=minans){
                minans=ans;
                ansind=i;
            }
        }
        return ansind;
    }
};
