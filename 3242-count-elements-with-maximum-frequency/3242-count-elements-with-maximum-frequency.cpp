class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>m;
        int ans=0;
        int maxi=INT_MIN;
        for(int i:nums){
            m[i]++;
            maxi=max(maxi,m[i]);
        }
        for(auto i:m){
            if(i.second==maxi) ans+=i.second;
        }
        return ans;
    }
};