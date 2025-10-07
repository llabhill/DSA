class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();

        unordered_map<int, int> mpp; //lake->last day it rained
        set<int> zeroRain; // indexes of Os

        vector<int> ans(n, -1);

        for(int i = 0; i<n; i++){
            int lake = rains[i];
            int day = i;

            if(lake == 0){
                zeroRain.insert(day);
                ans[day] = 1;
            }else{
                if(mpp.count(lake)){
                    auto it = zeroRain.lower_bound(mpp[lake]);

                    if(it == zeroRain.end()){
                        return {};

                    }
                    int dryday = *it;
                    ans[dryday] = lake;

                    zeroRain.erase(it);
                }
                mpp[lake] = day; // update last rain today
                ans[day] = -1; //raining today
            }
            
        }
        return ans;

        
    }
};