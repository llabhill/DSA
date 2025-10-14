class Solution {
public:
    bool isInc(vector<int>& nums,int j,int n){
        for(int i=j;i<n-1;i++){
            if(nums[i+1]<=nums[i]) return false;
        }
        return 1;

    }
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        if(k==1) return 1;
        for(int i=0;i+2*k<=nums.size();i++){
            bool first=isInc(nums,i,i+k);
            bool second=isInc(nums,i+k,i+2*k);
            if(first&&second) return 1;
        }
        return 0;
    }
};