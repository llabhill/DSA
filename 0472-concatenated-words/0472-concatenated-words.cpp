#include<bits/stdc++.h>
class Solution {
    unordered_map<string,bool> m;
    bool isconcatenated(string s,unordered_set<string> &st){
        if(m.find(s)!=m.end()){
            return m[s];
        }
        for(int i=0;i<s.length();i++){
            string prefix=s.substr(0,i+1);
            string suffix=s.substr(i+1);
            if((st.find(prefix)!=st.end()&&isconcatenated(suffix,st))
            ||(st.find(prefix)!=st.end()&&st.find(suffix)!=st.end())){
                return m[s]=true;
            }
            
        }
        return m[s]=false;
    }
    public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        m.clear();
        vector<string>ans;
        unordered_set<string> st(words.begin(),words.end());
        for(int i=0;i<words.size();i++){
            if(isconcatenated(words[i],st)){
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};