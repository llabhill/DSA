class Solution {
public:
    bool isBalanced(string num) {
        int c1=0;
        for(int i=0;i<num.size();i++){
            if(i%2==0) c1+=num[i]-'0';
            else c1-=num[i]-'0';
        }
        return c1==0;
    }
};