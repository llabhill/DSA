class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0,cnt2=0;
        int cand1=INT_MIN,cand2=INT_MIN;
        for(int i:nums){
            if(cand1==i) cnt1++;
            else if(cand2==i) cnt2++;
            else if(cnt1==0){
                cand1=i;
                cnt1++;
            }
            else if(cnt2==0){
                cand2=i;
                cnt2++;
            }
            
            else{
                cnt1--;
                cnt2--;
            }
        }
        int count1=0,count2=0;
        for(int j:nums){
            if(j==cand1) count1++;
            if(j==cand2) count2++;
        }
        vector<int> ans;
        if(count1>(nums.size()/3)) ans.push_back(cand1);
        if(count2>(nums.size()/3)) ans.push_back(cand2);
        sort(ans.begin(),ans.end());
        return ans;
    }
};