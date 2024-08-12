class Solution {
public:
    int sum(vector<int>&arr){
        int s=0;
        for (auto x:arr){
            cout<<x<<" ";
            s+=x;
        } 
        cout<<endl;
        return s;
    }
    int candy(vector<int>& ratings) {
        if(ratings.size()==1) return 1;
        int ans=ratings.size();
        vector<int>temp(ratings.size(), 1);
        int c=1;
        for (int i=0; i<ratings.size(); i++){
            if(i-1>=0){
                if(ratings[i]>ratings[i-1] && temp[i]<=temp[i-1]){
                    temp[i]=temp[i-1]+1;
                }
            }
            if(i+1<ratings.size()){
                if(ratings[i]>ratings[i+1] && temp[i]<=temp[i+1]){
                    temp[i]=temp[i+1]+1;
                }
            }
        }
        reverse(ratings.begin(), ratings.end());
        reverse(temp.begin(), temp.end());
        for (int i=0; i<ratings.size(); i++){
            if(i-1>=0){
                if(ratings[i]>ratings[i-1] && temp[i]<=temp[i-1]){
                    temp[i]=temp[i-1]+1;
                }
            }
            if(i+1<ratings.size()){
                if(ratings[i]>ratings[i+1] && temp[i]<=temp[i+1]){
                    temp[i]=temp[i+1]+1;
                }
            }
        }
        return sum(temp);
    }
};
