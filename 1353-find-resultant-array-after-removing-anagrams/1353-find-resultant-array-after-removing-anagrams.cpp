class Solution {
public:
    bool isana(string a,string b){
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        return a==b;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>ans;
        ans.push_back(words[0]);
        for(int i=1;i<words.size();i++){
            if(isana(words[i],words[i-1])){
                if(isana(words[i-1],ans.back())){
                    continue;  
                }
                else ans.push_back(words[i-1]); 
            }
            else ans.push_back(words[i]);
        }
        return ans;
    }
};