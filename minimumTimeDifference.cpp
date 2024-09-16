class Solution {
public:
    int findMinDifference(vector<string>& time) {
        vector<int>temp;
        for (int i=0; i<time.size(); i++){
            int dur=((time[i][0]-'0')*10 + (time[i][1]-'0') )*60 + 
                    ((time[i][3]-'0')*10 + (time[i][4]-'0') );
            temp.push_back(dur);
            // cout<<dur<<endl;
        }
        sort(temp.begin(), temp.end());
        int ans=INT_MAX;
        for (int i=0; i<temp.size()-1; i++){
            ans=min(ans, temp[i+1]-temp[i]);
        }
        ans=min(ans, 1440-temp[temp.size()-1]+temp[0]);
        return ans;
    }
};
