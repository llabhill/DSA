class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int currlen=1;
        int prelen=0;
        int k=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                currlen++;
            }
            else{
                prelen=currlen;
                currlen=1;
            }
            k=max(k,currlen/2);
            k=max(k,min(prelen,currlen));
        }
        return k;
    }
};