class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        unordered_map<int, int> map1;
        for (int i=0; i<n1; i++){
            int num=arr1[i];
            while(num>0){
                map1[num]++;
                num/=10;
            }
        }
        int ans=0;
        for (int i=0; i<n2; i++){
            int num=arr2[i];
            while(num>0){
                if(map1.find(num)!=map1.end()){
                    int length=to_string(num).length();
                    ans= max(ans, length);
                }
                num/=10;
            }
        }
        return ans;
    }
};
