class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size()<k) return 0;
        unordered_set<string>st;
        for(int i=0;i<=s.size()-k;i++){
            st.insert(s.substr(i,k));
        }
        return st.size()==pow(2,k);

    }
};