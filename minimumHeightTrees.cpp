class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};

        queue<int> q;
        unordered_map<int, vector<int> > adjlist;
        unordered_map<int, int > count;
        for ( auto x: edges){
            int u = x[0];
            int v = x[1];
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
            count[u]++;
            count[v]++;
        }
        vector<int>ans;
        for (auto x: count){
            if( x.second==1 ){
                q.push(x.first);
                ans.push_back(x.first);
            }
        }

        
        while(!q.empty()){
            vector<int>temp;
            int size=q.size();
            for (int i=0; i<size; i++){
                int node=q.front();
                q.pop();
                for (auto y : adjlist[node]){
                    count[y]--;
                    if(count[y]==1){
                        q.push(y);
                        temp.push_back(y);
                    }
                }
            }
            if(!q.empty()){
                ans=temp;
            }
        }
        return ans;
    }
};
