class Solution {
public:
    int getLucky(string s, int k) {
        vector<int>arr;
        for (int i=0; i<s.length(); i++){
            int sum=s[i]-'a'+1;
            if(sum/10!=0){
                arr.push_back(sum/10);
            }
            if(sum%10!=0){
                arr.push_back(sum%10);
            }
        }
        int ans=0;
        for (int i=0; i<k; i++){
            int sum=0;
            for (int j=0; j<arr.size(); j++){
                sum+=arr[j];
            }
            ans=sum;
            vector<int>temp;
            while(sum>0){
                temp.push_back(sum%10);
                sum=(sum-sum%10)/10;
            }
            arr=temp;
        }
        return ans;
    }
};
