class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        bool mp[26];
        for(char i:brokenLetters){
            mp[i-'a']=true;
        }
        int cnt=0;
        bool cantype=true;
        for(char ch:text){
            if(ch==' '){
                if(cantype){
                    cnt++;
                }
                cantype=true;
            }
            else if(mp[ch-'a']==true){
                cantype=false;
            }
        }
        if(cantype) cnt++;
        return cnt;
    }
};