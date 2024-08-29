class ihatemyself{
    public:
        int n;
        vector<int>father;
        vector<int>rank;
        ihatemyself(int n){
            this->n=n;
            vector<int>dummy1(n,-1);
            this->father=dummy1;
            vector<int>dummy2(n,1);
            this->rank=dummy2;
        }
        int search(int k){
            if(this->father[k]==-1) return k;
            return search(this->father[k]);
        }
        void uni(int u,int v){
            int grandu=search(u);
            int grandv=search(v);
            if(grandu!=grandv){
                if(rank[grandu]<=rank[grandv]) swap(grandu,grandv);
                this->father[grandu]=grandv;
                rank[grandu]+=rank[grandv];
            }
        }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=0;
        unordered_map<int,int>m;
        for (int i=0;i<stones.size();i++){
            n=max(n,max(stones[i][0],stones[i][1]));
        }
        int extra=2*n+2;
        ihatemyself *vro= new ihatemyself(extra);
        for (int i=0;i<stones.size();i++){
            if(m[stones[i][1]+n+1]!=1){ 
                m[stones[i][1]+n+1]=1;
                extra--;}
            if(m[stones[i][0]]!=1){ 
                
                m[stones[i][0]]=1;
                extra--;}
            vro->uni(stones[i][1]+n+1,stones[i][0]);
        }
        int ans=0;
        for (auto x:vro->father){
            if(x==-1) ans++;
            cout<<x<<"\n";
        }
        cout<<extra;
        return stones.size()-ans+extra;
    }
};
