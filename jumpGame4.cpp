//jump game4
class Solution {
public:
    class compare{
        public:
        bool operator()( pair<int,int> const &a, pair<int,int> const &b){
            return a.second>b.second;
        }
    };
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>>mp;
        vector<int>vis(arr.size(), 0);
        priority_queue<pair<int, int>, vector<pair<int,int> >, compare>q;
        q.push({0,0});
        for (int i=0; i<arr.size(); i++){
            mp[arr[i]].push_back(i);
        }
        while(q.empty()!=true){
            int top=q.top().first;
            int jump=q.top().second;
            // cout<<top<<" "<<jump<<endl;
            q.pop();
            if(top==arr.size()-1) return jump;
            if(vis[top]!=0) continue;
            vis[top]=1;
            int left=top-1;
            int right=top+1;
            if(left>=0 && left<arr.size() && vis[left]==0)
                q.push({left, jump+1});
            if(right>=0 && right<arr.size() && vis[right]==0)
                q.push({right, jump+1});
            if(mp.find(arr[top])!=mp.end()){
                for (auto x: mp[arr[top]]){
                    if(vis[x]==0 ){
                        q.push({x, jump+1});
                    }
                }
            }
            mp.erase(arr[top]);
        }
        return 0;
    }
};

