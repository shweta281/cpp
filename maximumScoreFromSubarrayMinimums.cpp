class Solution {
  public:
    // Function to find pair with maximum sum
    int pairWithMaxSum(vector<int> &arr) {
        stack<int>s;
        int ans=0;
        for (int i=0; i<arr.size(); i++){
            if(s.empty()==true){
                s.push(arr[i]);
            }
            else{
                int secondmin=s.top();
                ans=max(arr[i]+secondmin, ans);
                while(s.empty()!=true && arr[i]>s.top()) s.pop();
                s.push(arr[i]);
            }
        }
        return ans;
    }
};
