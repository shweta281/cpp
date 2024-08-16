class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int kmax=INT_MIN, kmin=INT_MAX;
        int kmaxindex=-1, kminindex=-1;
        for (int i=0; i<arrays.size(); i++){
            if(arrays[i][arrays[i].size()-1]>kmax){
                kmax=arrays[i][arrays[i].size()-1];
                kmaxindex=i;
            }
        }
        for (int i=0; i<arrays.size(); i++){
            if(i!=kmaxindex && arrays[i][0]<kmin){
                kmin=arrays[i][0];
                kminindex=i;
            }
        }
        int ans=kmax-kmin;
        kmax=INT_MIN;
        kmin=INT_MAX;
        for (int i=0; i<arrays.size(); i++){
            if(arrays[i][0]<kmin){
                kmin=arrays[i][0];
                kminindex=i;
            }
        }
        for (int i=0; i<arrays.size(); i++){
            if(i!=kminindex && arrays[i][arrays[i].size()-1]>kmax){
                kmax=arrays[i][arrays[i].size()-1];
                kmaxindex=i;
            }
        }
        ans=max(ans, kmax-kmin);
        return ans;
    }
};
