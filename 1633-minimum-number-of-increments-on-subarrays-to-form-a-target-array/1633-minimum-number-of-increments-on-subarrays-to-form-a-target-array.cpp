class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans=0;
        int curr=1;
        int prev=0;
        if(target[0]>0) ans+=(target[0]);
        while(curr<target.size()){
            if(target[curr]>target[prev]){
                ans+=(target[curr]-target[prev]);
            }
            curr++;
            prev++;
        }
        
        return ans;
    }
};