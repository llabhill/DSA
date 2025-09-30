class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n=nums.size()-1;
        while(n--){
            for(int i=0;i<nums.size()-1;i++){
                nums[i]=(nums[i]+nums[i+1])%10;
            }
        }
        return nums[0];

        
    }
};