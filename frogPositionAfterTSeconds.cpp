class Solution {
public:
// 0.33 
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        unordered_map<int, vector<int> > adjlist;
        for (auto x: edges){
            int u=x[0];
            int v=x[1];
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }
        for (auto x: adjlist){
            cout<<x.first<<":";
            for (auto y: x.second){
                cout<<y<<" ";
            }
            cout<<endl;
        }
        vector<int>vis(n, -1);
        queue<pair<double, pair<int, int>>> q;
        q.push({1, {1, t}});
        vis[0]=1;
        while(!q.empty()){
            int node=q.front().second.first;
            int time=q.front().second.second;
            double old_p=q.front().first;
            cout<<node<<" "<<old_p<<" "<<time<<endl;
            q.pop();
            int flag=0;
            if(time<0){
                continue;
            }
            int size= node==1? adjlist[node].size() : adjlist[node].size()-1;
            double new_p=old_p/size;
            int new_time=time-1;
            for (auto x: adjlist[node]){
                if(vis[x-1]!=-1){
                    continue;
                }
                // cout<<x<<endl;
                flag=1;
                q.push({new_p, { x, new_time}});
                vis[x-1]=1;
            }
            if(node==target){
                if(time==0 || !flag){
                    return old_p;
                } else {
                    return 0;
                }
            }
        }
        return 0;
    }
};
