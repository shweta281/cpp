
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        stack<int>s;
        vector<int>left;
        vector<int>right;
        for (int i=0;i<arr.size();i++){
            if(s.empty()){
                left.push_back(-1);
                s.push(i);
            }
            else{
                while(!s.empty() && arr[s.top()]>arr[i]){
                    s.pop();
                }
                if(s.empty()){
                    left.push_back(-1);
                }
                else{
                    left.push_back(s.top());
                }
                s.push(i);
            }
        }
        while(!s.empty()){
            s.pop();
        }
        for (int i=arr.size()-1;i>=0;i--){
            if(s.empty()){
                right.push_back(n);
                s.push(i);
            }
            else{
                while(!s.empty() && arr[s.top()]>=arr[i]){
                    s.pop();
                }
                if(s.empty()){
                    right.push_back(n);
                }
                else{
                    right.push_back(s.top());
                }
                s.push(i);
            }
        }
        reverse(right.begin(),right.end());
        int ans=0;
        for (int i=0;i<arr.size();i++){
            long long l=(i-left[i])%1000000007;
            long long r=(right[i]-i)%1000000007;
            long long temp= (arr[i]*l*r)%1000000007;
            ans=(ans%1000000007)+temp;
        }
        return ans%1000000007;
    }
};
