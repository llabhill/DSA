class Solution {
public:
    string smallestSubsequence(string s) {
        vector<bool> taken(26,false);
        vector<int> lastindex(26);
        string result;
        for(int i=0;i<s.size();i++){
            lastindex[s[i]-'a']=i;
        }
        for(int i=0;i<s.size();i++){
            int index=s[i]-'a';
            if(taken[index]==true) continue;
            while(result.length()>0&&result.back()>s[i]&&lastindex[result.back()-'a']>i){
               taken[result.back()-'a']=false;
                result.pop_back();
            }
            result.push_back(s[i]);
            taken[s[i]-'a']=true;
        }
        return result;
    }
};