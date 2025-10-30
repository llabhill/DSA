class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        long long ans=0;
        int curr=0;
        int prev=0;
        for(int i=0;i<target.size();i++){
            curr=target[i]-nums[i];
            if((curr>0&&prev<0)||(curr<0&&prev>0)) ans+=abs(curr);
            else if(abs(curr)>abs(prev)) ans+=abs(curr-prev);
            prev=curr;
        }
        return ans;
    }
};