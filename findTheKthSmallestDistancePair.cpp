class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int start=0, end=nums[nums.size()-1];
        int ans;
        while(start<end){
            int mid= (start+end)/2;
            int l=0, r=1, count=0;
            while(r<nums.size()){
                if(nums[r]-nums[l]>mid){
                    while(l<r && nums[r]-nums[l]>mid){
                        l++;
                    }
                }
                count+=(r-l);
                r++;
            }
            if(count>=k){
                end=mid;
            }
            else if(count<k){
                start=mid+1;
            }
        }
        return end;
    }
};
