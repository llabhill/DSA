class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>ans;
        sort(potions.begin(),potions.end());
        for(int i=0;i<spells.size();i++){
            int cnt=0;
            long long elm=ceil((double)success/spells[i]);
            auto it=lower_bound(potions.begin(),potions.end(),elm);
            if(it!=potions.end()){
                cnt+=potions.end()-it;
            }
            ans.push_back(cnt);

        }
        return ans;
    }
};