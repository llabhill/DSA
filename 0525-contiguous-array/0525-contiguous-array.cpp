class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        //sliding woindow not applicable
        //replace zero with -1 and find longest subaaray with sum==0;
        int currsum=0;
        unordered_map<int,int> m;
        int maxlen=0;
        m[0]=-1;
        for(int i=0;i<nums.size();i++){
            currsum+=nums[i]==1?1:-1;
            if(m.find(currsum)!=m.end()){
                maxlen=max(maxlen,i-m[currsum]);
            }
            else{
                m[currsum]=i;
            }

        }
        return maxlen;
    }
};